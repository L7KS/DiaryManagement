//
// Created by Jonathan R. on 19/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_d_list create_empty_list(int max_level){
    t_d_list list;
    if (max_level <= 0){
        max_level = 0;
    }
    list.max_level = max_level;
    list.heads = malloc(sizeof(ptr_cell)*max_level);
    for(int i = 0; i<max_level;i++){
        list.heads[i] = NULL;

    }
    return list;
}

void insert_head(t_d_list * list, ptr_cell cell) {
    if (list->heads[0] == NULL){
        for (int i=0; i<cell->level;i++){
            list->heads[i] = cell;
        }
        return;
    }
    for (int i=0; i<cell->level;i++){
        cell->nexts[i] = list->heads[i];
        list->heads[i] = cell;
    }
}

void display_list_at_level(t_d_list list, int level){
    level--;
    printf("[list head_%d @-]", level);
    ptr_cell head = list.heads[0];
    ptr_cell cell = list.heads[level];
    while (head != NULL){
        if (head == cell){
            printf("-->[%d|@-]",cell->value);
            cell = cell->nexts[level];
        }
        else{
            if (head->value < 10)
                printf("---------");
            else
                printf("----------");
        }
        head = head->nexts[0];
    }
    printf("-->NULL\n");
}

void display_list(t_d_list list){
    for (int i=1; i<=list.max_level; i++) {
        display_list_at_level(list, i);
    }
}

void insert_cell(t_d_list * list, ptr_cell cell){
    ptr_cell temp = NULL;
    for (int i = 0; i < cell->level+1; i++){
        if (list->heads[i] == NULL || list->heads[i]->value >= cell->value) {
            cell->nexts[i] = list->heads[i];
            list->heads[i] = cell;
        } else {
            temp = list->heads[i];
            while ((temp->nexts[i] != NULL) && (temp->nexts[i]->value < cell->value)) {
                temp = temp->nexts[i];
            }
            cell->nexts[i] = temp->nexts[i];
            temp->nexts[i] = cell;
        }
    }
}

int puissance(int a, int b){
    int res = 1;
    for (int i=0; i<b; i++)
        res = res * a;
    return res;
}

t_d_list create_list(int max_level){
    t_d_list list = create_empty_list(max_level);
    int * tab = calloc((puissance(2, max_level)-1) ,sizeof(int));
    int index = 0;

    for(int i = 0;i<max_level;i++){
        index = 0;
        while(index< puissance(2,max_level)){
            if(index!=0) {
                tab[index-1] = i;
            }
            index += puissance(2, i);

        }
    }

    if (max_level > 0){
        ptr_cell temp;
        for (int i = 0; i<puissance(2, max_level)-1; i++){
            temp = create_cell(i+1,tab[i]);
            insert_cell(&list, temp);
        }
    }
    return list;
}

int level_0_search(t_d_list list, int val){
    ptr_cell cell = list.heads[0];
    while ( cell != NULL){
        if (cell->value == val){
            return 1;
        }
        cell = cell->nexts[0];
    }
    return 0;
}

int high_level_search(t_d_list list, ptr_cell cell, int value){

    if(value == cell->value){
        return 1;
    }
    if(value>puissance(2,list.max_level)-1 || value<1){
        return 0;
    }
    else if ((cell->value < value) && (cell->level > 0)){
        for (int i=0; i<list.max_level; i++){
            list.heads[i] = cell->nexts[i];
        }
        return high_level_search(list, cell->nexts[cell->level - 1], value) != 0;
    }

    else if(cell->value> value && cell->level>0) {
        return high_level_search(list, list.heads[cell->level - 1], value) != 0;
    }
}

