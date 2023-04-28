#include "../include/Gestion_terrain.h"


/*
Fonction qui renvoie 1 si le joueur est dans la relique ou 0 sinon.
*/
int interaction_joueur_relique(Plateau *p){
    int i;
    assert(NULL != p);
    for(i = 0; i < NB_RELIQUE; ++i){
        if(est_dans_zone_objet(&(p->joueur.pos), &(p->relique[i].pos)) && p->relique[i].etat == NON_RECUPERER){
            change_etat_obj(&(p->relique[i].etat));
            p->joueur.nb_relique++;
            return 1;
        }
    }
    return 0;
}

/*
Permet à un joueur de récuperer la mana d'une tuile
*/
int interaction_joueur_tuile(Plateau *p){
    int i;
    assert(NULL != p);
    for(i = 0; i < NB_TUILE; ++i){
        if(est_dans_zone_objet(&(p->joueur.pos), &(p->tuile[i].pos)) && p->tuile[i].etat == NON_RECUPERER){
            change_etat_obj(&(p->tuile[i].etat));
            p->joueur.mana += p->tuile[i].mana;
            p->tuile[i].mana = 0;
            return 1;
        }
    }
    return 0;
}


/**
 * @brief Renvoie 1 si deux gardiens sont sur la même position et 0 sinon.
 * 
 * @param gardien_1 : Pointeur vers la structure Gardien, représentant un gardien.
 * @param gardien_2 : Pointeur vers la structure Gardien, représentant un autre gardien.
 * @return int : 1 si deux gardiens partage les mêmes coordonnées et 0 sinon.
 */
static int gardien_meme_position(Gardien *gardien_1, Gardien *gardien_2){
    assert(NULL != gardien_1);
    assert(NULL != gardien_2);
    return ((int)gardien_1->pos.x == (int)gardien_2->pos.x && (int)gardien_1->pos.y == (int)gardien_2->pos.y) ? 1 : 0;
}


/*
Permet à deux gardien de changer de deplacement s'il entre en collision.
*/
void interaction_gardien_gardien(Plateau *plateau){
    int i, j;
    assert(NULL != plateau);
    for(i = 0; i < NB_GARDIEN; ++i){
        for(j = 0; j < NB_GARDIEN; ++j){
            if(j != i && gardien_meme_position(&(plateau->gardien[i]), &(plateau->gardien[j]))){
                change_direction_(&(plateau->gardien[i].direction));
                change_vitesse_gardien(&(plateau->gardien[i].alerte), &(plateau->gardien[i].vitesse));

                change_direction_(&(plateau->gardien[j].direction));
                change_vitesse_gardien(&(plateau->gardien[j].alerte), &(plateau->gardien[j].vitesse));
            }
        }
    }
}

/**
 * @brief Permet de gerer les modes invisibles et accéléré du joueur.
 * 
 * @param joueur : Pointeur vers la structure Joueur, représentant le joueur.
 * @param mod : Pointeur vers la structure MLV_Keyboard_modifier.
 * @param cpt : Pointeur int représentant le compteur de mana disponible du joueur.
 * @param mana_conso : Pointeur entier représentant le compteur de mana utilisé du joueur.
 */
static void gestion_mode_joueur(Joueur *joueur, MLV_Keyboard_modifier *mod, int *cpt, int *mana_conso){
    assert(NULL != joueur);
    assert(NULL != mod);
    assert(NULL != cpt);
    assert(NULL != mana_conso);

    if(MLV_shift_key_was_pressed(*mod) && joueur->mana >= 2){
        joueur->mode = MODE_ACCELERE;
        joueur->mana -= 2;
        *cpt += 2;
        *mana_conso += 2;
    }
    else if(MLV_get_keyboard_state(MLV_KEYBOARD_SPACE) == MLV_PRESSED && joueur->mana >= 1){
        joueur->mode = MODE_INVISIBLE;
        joueur->mana -= 1;
        *cpt += 1;
        *mana_conso += 1;
    }
    else{
        joueur->mode = MODE_NORMAL;
    }
}


/*
Permet de gerer les deplacement du joueur par les touches z,q,s,d
*/
void deplacement_joueur(Plateau *plateau, MLV_Keyboard_button *sym, MLV_Button_state *state, MLV_Keyboard_modifier *mod){
    assert(NULL != plateau);
    assert(NULL != sym);
    assert(NULL != state);
    assert(NULL != mod);
    gestion_mode_joueur(&(plateau->joueur), mod, &(plateau->cpt_mana), &(plateau->mana_conso));
    if(*sym == MLV_KEYBOARD_z && *state == MLV_PRESSED){
        plateau->joueur.direction = HAUT;
        if(!collision_contre_mur(plateau, &(plateau->joueur.pos), &(plateau->joueur.direction), &(plateau->joueur.vitesse))){
            augmente_vitesse_joueur(&(plateau->joueur.mode), &(plateau->joueur.vitesse));
            plateau->joueur.pos.y -= plateau->joueur.vitesse; /*printf("P-HAUT ");*/
        }
    }
    else if(*sym == MLV_KEYBOARD_s && *state == MLV_PRESSED){
        plateau->joueur.direction = BAS;
        if(!collision_contre_mur(plateau, &(plateau->joueur.pos), &(plateau->joueur.direction), &(plateau->joueur.vitesse))){
            augmente_vitesse_joueur(&(plateau->joueur.mode), &(plateau->joueur.vitesse));
            plateau->joueur.pos.y += plateau->joueur.vitesse; /*printf("P-BAS ");*/
        }

    }
    else if(*sym == MLV_KEYBOARD_q && *state == MLV_PRESSED){
        plateau->joueur.direction = GAUCHE;
        if(!collision_contre_mur(plateau, &(plateau->joueur.pos), &(plateau->joueur.direction), &(plateau->joueur.vitesse))){
            augmente_vitesse_joueur(&(plateau->joueur.mode), &(plateau->joueur.vitesse));
            plateau->joueur.pos.x -= plateau->joueur.vitesse; /*printf("P-GAUCHE ");*/
        }
    }
    else if(*sym == MLV_KEYBOARD_d && *state == MLV_PRESSED){
        plateau->joueur.direction = DROITE;
        if(!collision_contre_mur(plateau, &(plateau->joueur.pos), &(plateau->joueur.direction), &(plateau->joueur.vitesse))){
            augmente_vitesse_joueur(&(plateau->joueur.mode), &(plateau->joueur.vitesse));
            plateau->joueur.pos.x += plateau->joueur.vitesse; /*printf("P-DROITE ");*/
        }
    }
    else{
        plateau->joueur.vitesse = VITESSE_NULLE;
    }
}

/*
Permet au mana consommé de retourner au tuile.
*/
void retour_mana_vers_tuile(Plateau *plateau){
    int i, quantite_mana;
    assert(NULL != plateau);
    if((plateau->cpt_mana % 60) != 0 || plateau->cpt_mana <= 0){
        return;
    }
    for(i = 0; i < NB_TUILE; ++i){
        if(plateau->cpt_mana == 0){
            return;
        }
        quantite_mana = plateau->tuile[i].mana;
        if(quantite_mana == 0 && plateau->tuile[i].etat == RECUPERER){
            plateau->cpt_mana -= QUANTITE_MANA_TUILE;
            plateau->tuile[i].mana += QUANTITE_MANA_TUILE;
            change_etat_obj(&(plateau->tuile[i].etat));
        }
    }
}



static void effectue_deplacement_gardien(Gardien *g){
    assert(NULL != g);
    switch(g->direction){
        case HAUT : g->pos.y -= g->vitesse; break;
        case BAS : g->pos.y += g->vitesse; break;
        case GAUCHE : g->pos.x -= g->vitesse; break;
        case DROITE : g->pos.x += g->vitesse; break;
        default : break;
    }
}



static void direction_opposer(Direction *d){
    assert(NULL != d);
    switch(*d){
        case HAUT : *d = BAS; break;
        case BAS : *d = HAUT; break;
        case GAUCHE : *d = DROITE; break;
        case DROITE : *d = GAUCHE; break;
        default : break;
    }
}

/*Permet de generer les nouveaux déplacement des gardiens.*/
void deplacement_gardien(Plateau *plateau){
    int i, tmp, flag;
    assert(NULL != plateau);
    for(i = 0; i < NB_GARDIEN; ++i){
        tmp = rand() % 50;
        flag = 0;
        if(!collision_contre_mur(plateau, &(plateau->gardien[i].pos), &(plateau->gardien[i].direction), &(plateau->gardien[i].vitesse))){
            if(tmp == 0){
                change_direction_(&(plateau->gardien[i].direction));
                change_vitesse_gardien(&(plateau->gardien[i].alerte), &(plateau->gardien[i].vitesse));
            }
            effectue_deplacement_gardien(&(plateau->gardien[i]));
        }
        else{
            if(flag == 0){
                direction_opposer(&(plateau->gardien[i].direction));
            }
            change_vitesse_gardien(&(plateau->gardien[i].alerte), &(plateau->gardien[i].vitesse));
            effectue_deplacement_gardien(&(plateau->gardien[i]));
        }
    }
}

/*Detecte la fin du jeu*/
int fin_de_jeu(Joueur const *j){
    assert(NULL != j);
    if(j->pos.x >= COORD_FIN_DE_JEU_X - MARGE_DISTANCE && j->pos.x <= COORD_FIN_DE_JEU_X + MARGE_DISTANCE &&
        j->pos.y >= COORD_FIN_DE_JEU_Y - MARGE_DISTANCE && j->pos.y <= COORD_FIN_DE_JEU_Y + MARGE_DISTANCE &&
         j->nb_relique == NB_RELIQUE){
            return 1;
    }
    return 0;
}
