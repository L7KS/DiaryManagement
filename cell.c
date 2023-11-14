//
// Created by Jonathan R. on 14/11/2023.
//

#include "cell.h"

t_d_cell *create_cell(int value, int levels)
{
    t_d_cell *cell = (t_d_cell *)malloc(sizeof(t_d_cell));
    cell->value = value;
    for (int i = 0; i < levels ; ++i) {
        cell->next_0(i) = NULL;
    }

    return cell;
}

