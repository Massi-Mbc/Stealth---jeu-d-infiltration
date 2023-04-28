#ifndef __COLLISION__
#define __COLLISION__

#define MARGE_DISTANCE 1.00
#include "Moteur_de_jeu.h"

/**
 * @brief Vérifie si un joueur partage la même position
 * qu'un objet du jeu, si c'est le cas on renvoie 1 sinon 0.
 * Sert notamment pour savoir si le joueur peut récupérer un objet.
 * 
 * @param joueur : pointeur vers la position du joueur.
 * @param objet : pointeur vers la position d'un objet de jeu.
 * @return int : 1 si le joueur et l'objet ont la même coordonnée et 0 sinon.
 */
int est_dans_zone_objet(Position *joueur, Position_obj *objet);

/*renvoie 1 si le joueur est sur un relique ou 0 sinon*/
/*int est_dans_relique(Joueur const *j, Relique const *r);*/

/*renvoie 1 si la pos du joueur est sur la meme pos que la tuile ou 0 sinon.*/
/*int est_dans_tuile(Joueur const *j, Tuile const *t);*/

/*verifie le gardien detecte le joeur*/
/**
 * @brief Vérifie si un gardien rencontre le joueur par son champs de vision.
 * Renvoie 1 si c'est le cas et 0 sinon.
 * 
 * @param p : Pointeur vers la structure Plateau (plateau de jeu principal).
 * @return int : Renvoie 1 si le joueur est détecté par l'un des gardiens et 0 sinon.
 */
int gardien_detecte_joueur(Plateau *p);


/**
 * @brief Vérifie si un gardien detecte la disparition d'une relique.
 * Renvoie 1 si c'est le cas et 0 sinon.
 * 
 * @param plateau : Pointeur vers la structure du Plateau.
 * @param sec : double representant le nombre de seconde écoulé depuis le début de la partie.
 * @return int : 1 si la relique à disparu et 0 sinon.
 */
int gardien_detecte_relique(Plateau *plateau, double *sec);


/**
 * @brief Calcule et renvoie la distance entre un agent (Joueur ou Gardien)
 * et le prochain mur par rapport aux coordonnée actuelle de l'agent.
 * 
 * @param plateau : Pointeur vers la structure du Plateau.
 * @param pos : Pointeur vers la structure Position, representant la position de l'agent.
 * @param dir : Pointeur vers la structure Direction, representant la direction de l'agent.
 * @return int : Entier representant la distance entre le mur et l'agent.
 */
int distance_vers_mur(Plateau const *plateau, Position const *pos, Direction const *dir);


/**
 * @brief Verifie et renvoie 1 s'il y a collision entre un mur et 
 * un agent (Joueur ou Gardien) et 0 sinon.
 * 
 * @param plateau : Pointeur vers la structure du Plateau.
 * @param pos : Pointeur vers la structure Position, représentant la position de l'agent.
 * @param dir : Pointeur vers la structure Direction, représentant la direction de l'agent.
 * @param vitesse : Pointeur vers double, représentant la vitesse de l'agent.
 * @return int : 1 s'il y a collision et 0 sinon.
 */
int collision_contre_mur(Plateau const *plateau, Position *pos, Direction const *dir, double *vitesse);

#endif
