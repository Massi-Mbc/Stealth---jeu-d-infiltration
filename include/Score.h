#ifndef __SCORE__
#define __SCORE__

#define MAX_SCORE 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @brief Structure de donnée permettant de gerer le score d'un joueur.
 */
typedef struct score {
    int used_mana; /*!<Quantité de mana utilisé pendant une partie.*/
    double time; /*!<Durée d'une partie.*/
    char username[20]; /*Pseudonyme du joueur*/
}Score;

/**
 * @brief Structure de donnée représentant le tableau de score.
 */
typedef struct tab_score {
    Score score[MAX_SCORE]; /*!<Tableau de score.*/
    int element; /*!<Nombre de score contenu dans le tableau.*/
}Tab_score;


/**
 * @brief Fonction permettant la saisie d'un score.
 * 
 * @param new_score : Pointeur vers la structure Score, representant le score à enrengistrer.
 * @param sec : Pointeur double représentant le nombre de seconde écoulé du début jusqu'a la fin de la partie.
 * @param ms : Pointuer double représentant le nombre de milliseconde écoulé du début jusqu'à la fin de la partie.
 * @param mana_conso : Pointeur entier representant la quantité de mana consommé par le joueur.
 */
void saisie_ici(Score *new_score, double *sec, double *ms, int *mana_conso);


/**
 * @brief Permet l'ajout d'un score dans le tableau de score.
 * 
 * @param s : Pointeur vers le tableau de score de la structure Tab_score.
 * @param new_score : Pointeur vers le nouveau score de la structure Score.
 * @return int : 1 si le score a pu être retenu et enrengistré et 0 sinon.
 */
int add_score(Tab_score *s, Score new_score);


/**
 * @brief Permet de lire le score à partir du fichier binaire score.
 * 
 * @param tmp : Pointeur vers la structure Tab_score.
 * @return int : 1 ou 2 en cas d'erreur avec le fichier et 0 sinon.
 */
int read_score_file(Tab_score *tmp);


/**
 * @brief Permet d'ajouter un score au tableau de score de la structure Tab_score.
 * 
 * @param new_score : Elément représentant le tableau de score contenant le nouveau score enrengister.
 * @return int : 1 ou 2 en cas d'erreur avec le fichier binaire et 0 sinon.
 */
int save_score(Tab_score new_score);
#endif
