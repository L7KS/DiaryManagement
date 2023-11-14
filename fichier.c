//
// Created by Jonathan R. on 08/11/2023.
//

#include "fichier.h"



t_d_list *create_list(int levels)
{
    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    list->head_0 = NULL;
    list->head_1 = NULL;
    return list;
}

void insert_head(t_d_list *list, t_d_cell *cell)
{
    if (cell->value % 2 == 0)
    {
        cell->next_0 = list->head_0;
        list->head_0 = cell;
    }
    else
    {
        cell->next_1 = list->head_1;
        list->head_1 = cell;
    }
}

void print_list(t_d_list *list, int level)
{
    if (level % 2 == 0)
    {
        t_d_cell *current = list->head_0;
        while (current != NULL)
        {
            printf("%d ", current->value);
            current = current->next_1;
        }
    }
}