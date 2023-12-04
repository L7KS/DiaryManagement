//
// Created by Jonathan R. on 08/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "cell.h"

int main()
{
    t_d_list list = create_empty_list(10);
    insert_cell(&list, create_cell(5,4));
    insert_head(&list, create_cell(6,5));
    display_list(list);
    return 0;
}

