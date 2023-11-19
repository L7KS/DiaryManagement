//
// Created by Jonathan R. on 19/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "cell.h"

t_d_list *create_list(int max_levels)
{
    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    list->max_levels = max_levels;
    list->heads = (t_d_cell *)malloc(sizeof(t_d_cell) * max_levels);

    return list;
}

void insert_head(t_d_list *list, int value)
{
    t_d_cell *cell = create_cell(value, list->max_levels);
    int i = 0;
    while (i < list->max_levels)
    {
        cell->nexts[i] = list->heads[i].nexts[i];
        list->heads[i].nexts[i] = (int) cell;
        i++;
    }
}

void insert_ordered(t_d_list *list, int value)
{
    t_d_cell *cell = create_cell(value, list->max_levels);
    int i = 0;
    while (i < list->max_levels)
    {
        cell->nexts[i] = list->heads[i].nexts[i];
        list->heads[i].nexts[i] = (int) cell;
        i++;
    }
}

void insertion(t_d_list *list, int value, int levels)
{
    t_d_cell *c = create_cell(value, levels);
    int i = list->max_levels;
while (i >= 0)
    {
        if (list->heads[i].nexts[i] == NULL)
        {
            list->heads[i].nexts[i] = (int) c;
            i--;
        }
        else
        {
            if (list->heads[i].nexts[i]->value > value)
            {
                c->nexts[i] = list->heads[i].nexts[i];
                list->heads[i].nexts[i] = (int) c;
                i--;
            }
            else
            {
                list->heads[i].nexts[i] = (int) c;
                i--;
            }
        }
    }
}

void display_list(t_d_list *list)
{
    int i = 0;
    while (i < list->max_levels)
    {
        printf("Level %d : ", i);
        t_d_cell *cell = (t_d_cell *) list->heads[i].nexts[i];
        while (cell != NULL)
        {
            printf("%d ", cell->value);
            cell = (t_d_cell *) cell->nexts[i];
        }
        printf("\n");
        i++;
    }
}