//
// Created by Jonathan R. on 14/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

t_d_cell *create_cell(int val, int levels)
{
    t_d_cell *cell = (t_d_cell *)malloc(sizeof(t_d_cell));
    if (levels < 0)
    {
        levels = 0;
    }
    cell->levels = levels;
    cell->value = val;
    cell->nexts = malloc(sizeof(t_d_cell *)*levels+1);
    for (int i = 0; i < levels+1; ++i) {
        (cell->nexts[i]) = NULL;
    }
    return cell;
}

