//
// Created by Jonathan R. on 19/11/2023.
//

#ifndef DIARYMANAGEMENT_LIST_H
#define DIARYMANAGEMENT_LIST_H
#include "cell.h"

typedef struct s_d_list
{
    int max_levels;
    t_d_cell ** heads;
} t_d_list;

t_d_list create_empty_list(int max_levels);
void insert_head(t_d_list * list, t_d_cell * cell);
void display_list_at_level(t_d_list list, int level);
void display_list(t_d_list list);
t_d_list create_list(int level);
int search_level_0_(t_d_cell * cell, int val);
#endif //DIARYMANAGEMENT_LIST_H
