#ifndef __GESTION_TERRAIN__
#define __GESTION_TERRAIN__

#include "Collision.h"
#include "MLV/MLV_all.h"
#include <unistd.h>

/*Toute les actions se font avec le plateau par pointeur*/


/**
 * @brief Gére les differentes interaction entre le joueur et les reliques.
 * Notamment si le joueur récupere une relique, celle-ci ira dans le compteur du joueur 
 * et disparaitra de l'écran de jeu.
 * 
 * @param p : Pointeur vers la structure Plateau, représentant le plateau de jeu principale.
 * @return int : Renvoie 1 si le joueur marche sur une relique et 0 sinon.
 */
int interaction_joueur_relique(Plateau *p);


/**
 * @brief Gére les differentes interaction entre le joueur et les tuiles.
 * Notamment si le joueur récupere une tuile, le mana qu'elle contient ira dans le compteur
 * de mana du joueur.
 * 
 * @param p : Pointeur vers la structure Plateau, représentant le plateau de jeu principale.
 * @return int : Renvoie 1 si le joueur passe dessus tuile et 0 sinon.
 */
int interaction_joueur_tuile(Plateau *p);


/**
 * @brief Permet de gérer les déplacements du joueur en temps réel, par les touches du claviers.
 * 
 * @param plateau : Pointeur vers la structure Plateau, représentant le plateau de jeu.
 * @param sym : Pointeur vers la structure MLV_Keyboard_button, contenant le numéro de la touche pressé.
 * @param state : Pointeur vers la structure MLV_Button_state, contenant l'état de la touche (presser ou non).
 * @param mod : Pointeur vers la structure MLV_Keyboard_modifier.
 */
void deplacement_joueur(Plateau *plateau, MLV_Keyboard_button *sym, MLV_Button_state *state, MLV_Keyboard_modifier *mod);


/**
 * @brief Permets aux gardiens d'effectuer des déplacements sur le plateau.
 * Eviter qu'il n'entre en collision avec un mur ou entre eux.
 * 
 * @param plateau : Pointeur vers la structure Plateau, représentant le plateau de jeu.
 */
void deplacement_gardien(Plateau *plateau);


/**
 * @brief Permets de changer la trajectoire de 2 gardiens qui rentrerait en collision.
 * 
 * @param p : Pointeur vers la structure Plateau.
 */
void interaction_gardien_gardien(Plateau *p);


/**
 * @brief Permets de rendre le mana utiliser par le joueur à une tuile ne contenant plus de mana.
 * 
 * @param plateau : Pointeur vers la structure Plateau.
 */
void retour_mana_vers_tuile(Plateau *plateau);


/**
 * @brief Permets à un gardien de sortir du mode panique (après 30 secondes de mode PANIQUE). 
 * 
 * @param plateau : Pointeur vers la structure Plateau.
 */
void sortie_du_mode_panique(Plateau *plateau);


/**
 * @brief Permets de detecter si le joueur remplie des conditions pour une fin de jeu.
 * Retourne 1 si le joueur possede les 3 reliques et qu'il se trouve dans ses coord initiale, ou 0 sinon.
 * 
 * @param j : Pointeur vers la structure Joueur, représentant le joueur.
 * @return int : 1 si le joueur remplie les conditions de victoire et 0 sinon.
 */
int fin_de_jeu(Joueur const *j);


#endif
