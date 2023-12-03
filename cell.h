//
// Created by Jonathan R. on 14/11/2023.
//

#ifndef DIARYMANAGEMENT_CELL_H
#define DIARYMANAGEMENT_CELL_H

#include <stdio.h>

typedef struct s_d_cell
{
    int value;
    struct s_d_cell ** nexts;
    int levels;
}t_d_cell;

t_d_cell *create_cell(int , int );
#endif //DIARYMANAGEMENT_CELL_H
