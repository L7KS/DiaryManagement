//
// Created by Jonathan R. on 14/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

t_d_cell *create_cell(int value, int levels)
{
    t_d_cell *cell = (t_d_cell *)malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->nbniveau = levels;
    cell->nexts = (int *)malloc(sizeof(int) * levels);

    return cell;
}

