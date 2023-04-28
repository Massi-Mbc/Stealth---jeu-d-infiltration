#ifndef __MOTEUR_DE_JEU__
#define __MOTEUR_DE_JEU__

#include "Relique.h"
#include "Gardien.h"
#include "Joueur.h"
#include <assert.h>
#include <math.h>

#define LARGEUR_PLATEAU 45
#define LONGEUR_PLATEAU 60
#define DISTANCE_MIN_JOUEUR_GARDIEN_OBJ 20
#define NB_RELIQUE 3
#define NB_GARDIEN 5
#define NB_TUILE 20
#define QUANTITE_MANA_TUILE 60
#define LIMITE_NB_PANIQUE 3
#define minside 9

/**
 * @brief Enumere les differents éléments du jeu.
 */
typedef enum element_de_jeu{
    VIDE, /*!<représente les cases vides*/
    MUR, /*!<représente les murs du jeu*/
    GARDIEN, /*!<représente les gardiens du jeu*/
    RELIQUE, /*!<représente les reliques du jeu*/
    JOUEUR, /*!<représente le joueur*/
    TUILE /*!<représente les tuiles du jeu*/
}Element_de_jeu;


/**
 * @brief Structure de donnée représentant une tuile.
 */
typedef struct tuile{
    Etat_objet etat; /*!<Etat de l'objet, s'il est récuperer ou non.*/
    Position_obj pos; /*!<Position 2D d'un tuile*/
    int mana;/*60*/
}Tuile;

/**
 * @brief Structure de donnée représentant le plateau de jeu.
 */
typedef struct plateau{
    int cpt_mana, mana_conso; /*!<Entier representant la mana consommer par le joueur.*/
    int plateau[LARGEUR_PLATEAU][LONGEUR_PLATEAU]; /*!<Plateau principale de jeu.*/
    Joueur joueur; /*!<Structure contenant le joueur.*/
    Gardien gardien[NB_GARDIEN]; /*!<Tableau contenant les gardiens.*/
    Relique relique[NB_RELIQUE]; /*!<Tableau contenant les reliques.*/
    Tuile tuile[NB_TUILE]; /*!<Tableau contenant les tuiles */
} Plateau;




/**
 * @brief Crée le contenu du plateau et initialise ses elements.
 * 
 * @param game : pointeur sur la structure Plateau.
 */
void create_map(Plateau *game);


/**
 * @brief Change l'état d'une relique ou d'une tuile, selon le fait qu'elle à été recupéré par le joueur.
 * 
 * @param o : pointeur sur la structure Etat_obj, représentant l'état d'une tuile ou d'une relique.
 */
void change_etat_obj(Etat_objet *o);

#endif
