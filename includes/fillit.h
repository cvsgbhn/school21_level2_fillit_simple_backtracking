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
    int                 x_shift;
    int                 y_shift;
    char                letter;
    struct s_tetromino  *next;

}                       t_element;

/*
 * TESTS
 */
void    test_print_structure(t_element *tetromino);

/*
 * t_element routine
 */
t_element	create_t_element(char letter);
void	add_last_t_element(t_element** head, t_element *new_node);

/*
 * reader routine
 */
int     *find_old_coordinates(char *tetromino);
int   *parse_to_xy(int coords[8], char xory);
int     min_in_array(int *numbers);
void   find_new_coordinates(int tetro_coords[4], int xory_coords[4];
int	get_one_tetromino(t_element *new_element, int fd, char letter);
t_element	*get_tetrominos(int fd);
t_element     *reader();


/*
 * solver routine
 */
#endif //SCHOOL21_LEVEL2_FILLIT_SIMPLE_BACKTRACKING_FILLIT_H
