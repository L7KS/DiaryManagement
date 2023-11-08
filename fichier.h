//
// Created by Jonathan R. on 08/11/2023.
//

#ifndef DIARYMANAGEMENT_FICHIER_H
#define DIARYMANAGEMENT_FICHIER_H

typedef struct s_d_cell
{
    int value;
    struct s_d_cell *next_0;
    struct s_d_cell *next_1;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell *head_0;
    t_d_cell *head_1;
} t_d_list;

#endif //DIARYMANAGEMENT_FICHIER_H
