//
// Created by Jonathan R. on 08/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "cell.c"
#include "list.c"

int main()
{
    t_d_list list = create_empty_list(3);
    insert_cell(&list, create_cell(5, 3));
    insert_cell(&list, create_cell(3, 3));
    insert_cell(&list, create_cell(7, 3));
    display_list(list);
    printf("Search result: %d\n", high_level_search(list, list.heads[0], 7));

    return 0;
}

