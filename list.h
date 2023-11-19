//
// Created by Jonathan R. on 19/11/2023.
//

#ifndef DIARYMANAGEMENT_LIST_H
#define DIARYMANAGEMENT_LIST_H

typedef struct s_d_cell
{
    int value;
    int nbniveau;
    int * nexts;
} t_d_cell;

typedef struct s_d_list
{
    int max_levels;
    t_d_cell * heads;
} t_d_list;

void insert_head(t_d_list * list, int value);
void insert_ordered(t_d_list * list, int value);
void insertion(t_d_list * list, int value, int levels);
void display_list(t_d_list * list);
#endif //DIARYMANAGEMENT_LIST_H
