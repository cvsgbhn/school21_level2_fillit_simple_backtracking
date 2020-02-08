//
// Created by ubuntuser on 09.02.2020.
//

#ifndef SCHOOL21_LEVEL2_FILLIT_SIMPLE_BACKTRACKING_FILLIT_H
#define SCHOOL21_LEVEL2_FILLIT_SIMPLE_BACKTRACKING_FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct          s_tetromino
{
    int                 x_coords[4];
    int                 y_coords[4];
    char                letter;
    struct s_tetromino  *next;

}                       t_element;


#endif //SCHOOL21_LEVEL2_FILLIT_SIMPLE_BACKTRACKING_FILLIT_H
