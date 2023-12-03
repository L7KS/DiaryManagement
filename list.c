//
// Created by Jonathan R. on 19/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "cell.h"

t_d_list create_empty_list(int max_levels)
{
    t_d_list list;
    if (max_levels <=0){
        max_levels = 0;
    }
    list.max_levels = max_levels;
    list.heads = malloc(max_levels * sizeof(t_d_cell *));
    for (int i = 0; i< max_levels;++i){
        list.heads[i] = NULL;
    }
    return list;
}

void insert_head(t_d_list * list, t_d_cell * cell) {
    if (list->heads[0] == NULL){
        for (int i = 0;i < cell->levels; ++i){
            list->heads[i] = cell;
        }
    }
    for (int i = 0; i < cell->levels; i++) {
        cell->nexts[i] = list->heads[i];
        list->heads[i] = cell;
    }
}

void display_list_at_level(t_d_list list, int level) {
    if (level == 1){
        level--;
    }
    printf("[list head %d @-]", level);
    t_d_cell * head = list.heads[0];
    t_d_cell * cell = list.heads[level];
    while (head != NULL){
        if (head == cell){
            printf("-->[%d|@-]",cell->value);
            cell = cell->nexts[level];
        }
        if (head->value < 10)
        {
            printf("---------");
        }
        else{
            printf("----------");
        }
        head = head->nexts[0];
    }
    printf("-->NULL\n");
}

void display_list(t_d_list list){
    for (int i = 1; i< list.max_levels;++i){
        display_list_at_level(list, i);
    }
}

int search_level_0_(t_d_list * list, int val){
    t_d_cell * cell = list->heads[0];
    while (cell != NULL){
        if (cell->value == val){
            return 1;
        }
        cell = cell->nexts[0];
    }
    return 0;
}



