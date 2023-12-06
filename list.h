//
// Created by Jonathan R. on 19/11/2023.
//

#ifndef DIARYMANAGEMENT_LIST_H
#define DIARYMANAGEMENT_LIST_H
#include "cell.h"

typedef struct s_list
{
    ptr_cell *heads; // tableau de pointeurs
    int max_level;
} t_d_list, *ptr_list;

t_d_list create_empty_list(int max_size);
void insert_head(ptr_list list, ptr_cell cell);
void display_list_at_level(t_d_list list, int level);
void display_list(t_d_list list);
void insert_cell(ptr_list list, ptr_cell cell);
t_d_list create_list(int max_size);
int puissance(int a, int b);
int level_0_search(t_d_list list, int val);
int high_level_search(t_d_list list, ptr_cell head, int val);


#endif //DIARYMANAGEMENT_LIST_H
