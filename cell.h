//
// Created by Jonathan R. on 14/11/2023.
//

#ifndef DIARYMANAGEMENT_CELL_H
#define DIARYMANAGEMENT_CELL_H
#include <stdio.h>
#include <stdlib.h>


typedef struct s_cell
{
    int value;
    struct s_cell ** nexts; // tableau de pointeurs
    int level;
} t_d_cell, *ptr_cell;

ptr_cell create_cell(int val,int level);
#endif //DIARYMANAGEMENT_CELL_H
