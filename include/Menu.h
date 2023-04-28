#ifndef __MENU__
#define __MENU__

#define NB_CASE_HAUTEUR 60
#define NB_CASE_LARGEUR 45
#define HAUTEUR_FENETRE LONGUEUR_FENETRE
#define DIFFERENCE_HAUTEUR HAUTEUR_FENETRE / NB_CASE_HAUTEUR
#define DIFFERENCE_LARGEUR LARGEUR_FENETRE / NB_CASE_LARGEUR
#define DELAI_ATTENTE 5
#define LANCE_JEU 3
#define OPTION_JEU 2
#define LOOSE 1
#define WIN 2
#define INCREMENTE_SCORE(i) (i + 2)
#include "Moteur_graphique.h"
#include "Score.h"
#include <assert.h>

/**
 * @brief Structure qui énumere les différents mode disponible du menu.
 */
typedef enum {
    MENU, /*!<Valeur par defaut du menu*/
    JEU, /*!<Passage du menu en mode jeu*/
    OPTION /*!<Passage du menu en mode option de menu*/
}Menu;

/**
 * @brief Structure qui énumere le mode retour du menu.
 */
typedef enum {
    RETOUR, /*!<Valeur par defaut du retour*/
    AUTRE /*!<Faisant office de tout autre bouton*/
}Retour;




/**
 * @brief Fabrique une case dont le nom est menu.
 * 
 * @param nom_case : Tableau de caractère, représentant le nom de la case à fabriquer.
 * @param taille_interlinge : entier représentant la taille de l'interligne.
 * @param type_case : entier représentant le type de case. (LANCE_JEU)
 */
void fabrique_case_menu(char nom_case[], int taille_interlinge, int type_case);


/**
 * @brief Fabrique une case dont le nom est retour.
 * 
 * @param nom_case : Tableau de caractère, représentant le nom de la case à fabriquer.
 * @param taille_interlinge : entier représentant la taille de l'interligne.
 * @param largeur : Entier représentant la largeur de la case.
 */
void fabrique_case_retour(char nom_case[], int taille_interlinge, int largeur);


/**
 * @brief Récupère les cases fabriquées, et les affiches sur la fenêtre graphique MLV.
 * 
 * @param nom_case_1 : Tableau de caractère représentant le nom de la case 1.
 * @param nom_case_2 : Tableau de caractère représentant le nom de la case 2.
 * @param taille_interlinge : Entier représentant la taille de l'interligne pour les deux cases.
 * @param type_case_1 : Entier représentant le type de la case 1.
 * @param type_case_2 : Entier représentant le type de la case 2.
 */
void affiche_case_menu(char nom_case_1[], char nom_case_2[], int taille_interlinge, int type_case_1, int type_case_2);

/**
 * @brief Permet l'affichage des options du menu sur la fenêtre graphique.
 * 
 * @param nom_case_1 : Tableau de caractère représentant le nom de la case 1.
 * @param nom_case_2 : Tableau de caractère représentant le nom de la case 2.
 * @param taille_interlinge : Entier représentant la taille de l'interligne pour les deux cases.
 * @param type_case_1 : Entier représentant le type de la case 1.
 * @param type_case_2 : Entier représentant le type de la case 2.
 */
void affiche_option(char nom_case_1[], char nom_case_2[], int taille_interlinge, int type_case_1, int type_case_2);

/**
 * @brief Affiche le menu entier sur la fenêtre graphique MLV.
 */
void affiche_menu();

/**
 * @brief Affiche l'écran de fin de jeu (message sous forme de texte), sur la fenêtre graphique MLV.
 * 
 * @param fin_de_jeu : Pointeur entier, représentant la victoire ou la defaite du joueur.
 * @param s : Pointeur entier, représentant le nombre de seconde écoulé du début jusqu'à la fin de la partie.
 * @param ms : Pointeur entier, représentant le nombre de milliseconde écoulé du début jusqu'à la fin de la partie.
 * @param mana : Pointeur entier, représentant la quantité de mana utiliser par le joueur durant la partie.
 */
void ecran_fin_de_jeu(int *fin_de_jeu, double *s, double *ms, int *mana);

/**
 * @brief Fonction permettant l'affichage du score du joueur, avec ceux déjà enrengistrés.
 * 
 * @param s : Pointeur entier, représentant le nombre de seconde écoulé du début jusqu'à la fin de la partie.
 * @param ms : Pointeur entier, représentant le nombre de milliseconde écoulé du début jusqu'à la fin de la partie.
 * @param mana : Pointeur entier, représentant la quantité de mana utiliser par le joueur durant la partie.
 */
void affiche_score(double *s, double *ms, int *mana);

#endif
