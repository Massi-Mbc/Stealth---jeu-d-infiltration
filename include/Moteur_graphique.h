#ifndef __MOTEUR_GRAPHIQUE__
#define __MOTEUR_GRAPHIQUE__

#include "Gestion_terrain.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define TAILLE_CASE 15
#define LONGUEUR_FENETRE (LONGEUR_PLATEAU * TAILLE_CASE)
#define LARGEUR_FENETRE (LARGEUR_PLATEAU * TAILLE_CASE)
#define EXTENSION 100

/*
0 : case vide
1 : mur
2 : gardien
3 : relique
4 : joueur
*/


/**
 * @brief Dessine le contenu de la fenêtre graphique avec le contenu issue du plateau de jeu.
 * 
 * @param p : Pointeur vers la structure Plateau, représentant le plateau de jeu principale.
 * @param longueur : Entier représentant la longueur de la fenêtre graphique.
 * @param largeur : Entier représentant la largeur de la fenêtre graphique.
 * @param sec : Pointeur entier représentant le nombre de seconde écoulé depuis le début d'une partie.
 */
void dessine_plateau_graphique(Plateau const *p, int longueur, int largeur, double *sec);

#endif
