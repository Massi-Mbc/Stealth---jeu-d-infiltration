#ifndef __GARDIEN__
#define __GARDIEN__

#define NORMAL 4
#define PANIQUE 6
#define TEMPS_PANIQUE 30

#include "Deplacement.h"

/**
 * @brief Enumere les états que peut prendre un gardien par rapport à la disparition d'une relique.
 */
typedef enum{
    MODE_NORMAL, /*!<Mode par defaut du gardien.*/
    MODE_PANIQUE /*!<Mode dans lequel entre un gardien lorsqu'il decouvre qu'un relique a disparu.*/
}Etat_gardien;

/**
 * @brief Enumere les états dans lequel le joueur est par rapport à un gardien.
 */
typedef enum{
    JOUEUR_NON_DETECTE, /*!<Etat par defaut du gardien.*/
    JOUEUR_DETECTE /*!<Etat dans lequel entre un gardien lorsqu'il detecte le joueur.*/
}Etat_detecte;

/**
 * @brief Structure representant un gardien.
 */
typedef struct gardien {
    int cpt_panique; /*!<Nombre de fois en mode panique.*/
    Etat_gardien alerte; /*!<type d'alerte du gardien.*/
    Etat_detecte detecte; /*!<detection d'un joueur.*/
    int distance_detection; /*!<(cercle) rayon de detection d'un gardien.*/
    Direction direction; /*!<Direction du gardien*/
    Position pos; /*!<Position 2D du gardien*/
    double vitesse; /*!<Vitesse du gardien.*/
    double chrono_panique; /*!<Nombre de seconde en mode panique*/
}Gardien;


/**
 * @brief Permet de changer la vitesse d'un gardien par pointeur.
 * 
 * @param etat : Pointeur vers la structure Etat_gardien, représentant le type d'alerte d'un gardien.
 * @param vitesse : Pointeur double vers la vitesse d'un gardien.
 */
void change_vitesse_gardien(Etat_gardien *etat, double *vitesse);


/**
 * @brief Permet le changement de direction d'un gardien par pointeur.
 * 
 * @param d : Pointeur vers la structure Direction, représentant la direction d'un gardien.
 */
void change_direction_(Direction *d);


/**
 * @brief Permet de configurer un gardien en mode NORMAL par pointeur.
 * Utile lorsqu'il sort du mode PANIQUE.
 * 
 * @param g : Pointeur vers la structure Gardien.
 */
void config_gardien_mode_normal(Gardien *g);


/**
 * @brief Permet de configurer un gardien en mode PANIQUE par pointeur.
 * Utile lorsqu'il entre en mode PANIQUE.
 * 
 * @param g : Pointeur vers la structure Gardien.
 */
void config_gardien_mode_panique(Gardien *g);


/**
 * @brief Permet d'initialiser par pointeur en début de partie.
 * 
 * @param g : Pointeur vers la structure Gardien.
 */
void initalise_gardien(Gardien *g);


/**
 * @brief Permet l'affichage d'information d'un gardien.
 * 
 * @param g : Pointeur vers la structure Gardien.
 */
void affiche_info_gardien(Gardien *g);

#endif
