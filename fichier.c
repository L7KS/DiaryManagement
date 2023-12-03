//
// Created by Jonathan R. on 08/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "cell.c"
#include "list.c"

int main()
{
    t_d_list list;
    list = create_empty_list(5);
    insert_head(&list, create_cell(5, 2));
    insert_head(&list, create_cell(6, 3));
    insert_head(&list, create_cell(7, 1));
    display_list(list);
}

