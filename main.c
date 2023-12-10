//
// Created by Jonathan R. on 08/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "cell.h"
int main()
{
    printf("Premiere Partie :\n");
    printf("Creer une liste vide: \n");
    t_d_list list = create_empty_list(9);
    display_list(list);
    printf("Ajouter en tete de liste:\n");
    t_d_list list1 = create_empty_list(3);
    insert_head(&list1, create_cell(1,2));
    display_list(list1);
    printf("Ajouter une cellule dans la liste 1:\n");
    insert_cell(&list1, create_cell(3, 1));
    display_list(list1);

    int value;
    printf("Partie 2: \n");
    printf("Creation d'une liste 2^n-1: \n ");
    t_d_list list2 = create_list(3);
    display_list(list2);
    printf("Recherche d'une valeur lvl 0 :\n");
    printf("La valeur est trouve %d", level_0_search(list2, 3));
    printf("\nRecherche d'une valeur tous les niveaux :");
    value= high_level_search(list2, list2.heads[4-1], 8);
    printf("\nLa valeur est trouve %d :",value);
    return 0;
}

