//
// Created by Jonathan R. on 08/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "cell.h"

int main()
{
    t_d_cell *cell = create_cell(2,5);
    t_d_list list = create_empty_list(10);
    insert_head(&list, create_cell(1,3));
    insert_cell(&list, create_cell(5,4));
    insert_cell(&list, create_cell(7,2));
    insert_cell(&list, create_cell(5,4));
    insert_cell(&list, create_cell(7,9));
    insert_cell(&list, create_cell(1,2));
    insert_cell(&list, create_cell(6,2));
    display_list(list);
    printf("Recherche de la valeur 5 dans la liste lvl 0");
    printf("La valeur est trouve\n %d", high_level_search(list,*cell,8));
    return 0;
}

