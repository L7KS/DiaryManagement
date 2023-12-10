//
// Created by Jonathan R. on 14/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

/**
 * Fonction pour créer une cellule avec une valeur et un niveau spécifiés.
 * @param val La valeur de la cellule.
 * @param level Le niveau de la cellule.
 * @return Une cellule avec la valeur et le niveau spécifiés.
 */

ptr_cell create_cell(int val, int level){
    ptr_cell cell = malloc(sizeof(t_d_cell));
    if ( level < 0){
        level = 0;
    }
    cell->level = level;
    cell->value = val;
    cell->nexts = malloc((level+1) * sizeof(ptr_cell ));
    for(int i = 0; i < level+1; i++){
        *(cell->nexts+i) = NULL;
    }
    return cell;
}

