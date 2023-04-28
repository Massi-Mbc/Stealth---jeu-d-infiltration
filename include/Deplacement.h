#ifndef __DEPLACEMENT__
#define __DEPLACEMENT__

#define VITESSE_NULLE 0.0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>

/**
 * @enum Direction
 * @brief Représente la direction d'un joueur et d'un gardien.
 */
typedef enum{
    HAUT, 
    BAS,
    GAUCHE,
    DROITE
}Direction;

/**
 * @brief Représente la position d'une relique ou d'une tuile.
 */
typedef struct position_obj{
    int x, y; /*!<position 2D d'un objet*/
}Position_obj;

/**
 * @brief Représente la position d'un joueur ou d'un gardien.
 */
typedef struct position{
    double x, y; /*!<position 2D d'un joueur ou d'un gardien*/
}Position;

#endif
