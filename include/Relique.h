#ifndef __RELIQUE__
#define __RELIQUE__


#include "Deplacement.h"
#include <assert.h>

/**
 * @brief Enumere les états que peut prendre un objet du jeu (tuile ou relique)
 */
typedef enum{
    NON_RECUPERER, /*!<mode par defaut d'un objet.*/
    RECUPERER /*!<Mode dans lequel entre un objet quand il est récuperer par le joueur.*/
}Etat_objet;


/**
 * @brief Structure de donnée représentant une relique.
 */
typedef struct relique{
    Etat_objet etat; /*!<Etat récuperer ou non d'une relique.*/
    Position_obj pos; /*!<Position 2D d'une relique.*/
}Relique;



/**
 * @brief Initialise une relique par pointeur.
 * 
 * @param r : Pointeur vers la structure Relique.
 */
void initialise_relique(Relique *r);


/**
 * @brief Affiche les informations à propos d'une relique.
 * 
 * @param r : Pointeur vers la structure Relique.
 */
void affiche_info_relique(Relique const *r);

#endif
