//
// Created by Jonathan R. on 19/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

void insert_cell (t_d_list *list, t_d_cell * cell){
    t_d_cell * temp = NULL;
    for (int i = 0; i < cell->levels+1; ++i) {
        if ((list->heads[i]==NULL)||(list->heads[i] >= cell->value)){
            cell->nexts = list->heads[i];
            list->heads[i] = cell;
        } else{
            temp = list->heads[i];
            while (temp->nexts[i]!=NULL && temp->nexts[i]->value < cell->value){
                temp = temp->nexts[i];
            }
            cell->nexts[i] = temp->nexts[i];
            temp->nexts[i] = cell;
        }
    }
}

int puissance(int a, int b){
    int res = 1;
    for (int i = 0; i < b; ++i) {
        res = res * a;
    }
    return res;
}
t_d_list create_list(int max_levels){
    t_d_list list = create_empty_list(max_levels);
    int * tab = calloc((puissance(2,max_levels)-1),sizeof(int ));
    int index = 0;
    for (int i = 0; i < max_levels; ++i) {
        while (index < puissance(2,max_levels)){
            if(index !=0){
                tab[index-1] = i;
            }
            index = index + puissance(2,i);
        }
    }
    if (max_levels > 0){
        t_d_cell * cell;
        for (int i = 0; i < puissance(2,max_levels)-1; ++i) {
            cell = create_cell(i+1,tab[i]);
            insert_cell(&list, cell);
        }
    }
}

int level0_search(t_d_list list, int val){
    t_d_cell * cell = list.heads[0];
    while (cell != NULL){
        if (cell->value == val){
            return 1;
        }
        cell = cell->nexts[0];
    }
    return 0;
}

int high_level_search(t_d_list list, t_d_cell * cell, int value){
    if(value == cell->value){
        return 1;
    }
    if ((cell->value < value) && (cell->levels > 0)){
        for (int i=0; i<list.max_levels; i++){
            list.heads[i] = cell->nexts[i];
        }
        return high_level_search(list, cell->nexts[cell->levels - 1], value) != 0;
    }

    {
        return high_level_search(list,list.heads[cell->levels - 1], value) != 0;
    }
}



