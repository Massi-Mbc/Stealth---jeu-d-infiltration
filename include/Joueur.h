#ifndef __JOUEUR__
#define __JOUEUR__

#define LONGUEUR 60
#define LARGEUR 45
#define VITESSE_JOUEUR_BASE 0.1
#define COORD_FIN_DE_JEU_X 2
#define COORD_FIN_DE_JEU_Y 2
#define INCREMENTE_VITESSE_JOUEUR 0.03

#include "Deplacement.h"
#include <assert.h>

/**
 * @brief Enumere les differents mode que peux prendre le joueur.
 */
typedef enum{
    AUCUN_MODE, /*!<Mode par defaut*/
    MODE_INVISIBLE, /*!<Mode d'invisibilité quand la touche 'espace' est presser.*/
    MODE_ACCELERE /*!<Mode de vitesse décupler quand la touche 'shift' est presser.*/
}Mode_joueur;


/**
 * @brief Structure de donnée d'un Joueur.
 */
typedef struct joueur{
    int nb_relique; /*!<Nombre de relique recuperer.*/
    int mana; /*!<Quantité de mana disponible.*/
    Direction direction; /*!<Direction du joueur.*/
    Mode_joueur mode; /*!<Mode dans lequel le joueur se trouve.*/
    double vitesse; /*!<Vitesse du joueur.*/
    Position pos; /*!<Position 2D du joueur*/
}Joueur;




/**
 * @brief Permet d'initialiser la vitesse du joueur par pointeur.
 * 
 * @param vitesse : Pointeur double representant la vitesse d'un joueur.
 */
void init_vitesse_joueur(double *vitesse);


/**
 * @brief Augmente graduellement la vitesse d'un jouueur par pointeur.
 * 
 * @param mode : Pointeur vers la structure Mode_joueur, représentant le mode du joueur.
 * @param vitesse : Pointeur double, représentant la vitesse d'un joueur.
 */
void augmente_vitesse_joueur(Mode_joueur *mode, double *vitesse);


/**
 * @brief Configure le joueur en mode normal (par pointeur).
 * 
 * @param j : Pointeur vers la structure Joueur.
 */
void config_joueur_mode_normal(Joueur *j);


/**
 * @brief Initialise un joueur pour le début de partie par pointeur.
 * 
 * @param j : Pointeur vers la structure Joueur.
 */
void initialise_joueur(Joueur *j);

/**
 * @brief Permet l'affichage d'information du joueur.
 * 
 * @param j : Pointeur vers la structure Joueur.
 */
void affiche_info_joueur(Joueur const *j);

#endif
