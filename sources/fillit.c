# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "fillit.h"

/*
* almost the same like move tetromino further - rollback.
* but only for x axys.
* may be there will be one for y rollback, i have no fucking idea
*/
void    coords_rollback(int last, int xory[4])
{
    int     counter;
    printf("%s\n", "ENTERED preparing_routine.c/coords_rollback :14");


    counter = -1;
    while (counter++ < last)
        xory[counter]--;
}

/*
* move tetrimino figure on the board, one position further to the right.
* we need here to recalculate coordinates for every spot.
* if any single spot coordinate > size of board: rollback,
* move further down the board.
* if the end of board reached - return something like nothing
*/
int    move_tetromino_once(int square_size, int x_coords[4], int y_coords[4])
{
    int     ox;
    int     oy;
    printf("%s\n", "ENTERED preparing_routine.c/move_tetromino_once :33");

    ox = -1;
    oy = -1;
    while (ox++ < 4)
    {
        if (x_coords[ox] > square_size)
        {
            coords_rollback(ox, x_coords);
            while (oy++ < 4)
            {
                y_coords[oy]++;
                if (y_coords[oy] >square_size)
                    return(-1);
            }
        }
        x_coords[ox]++;
    }
    return (1);
}

/*
* write original coordinates of every point of tetromino
* in a single array
*/
int     *find_old_coordinates(char *tetromino)
{
    int     rows_num;
    int     counter;
    int     *coordinates;
    int     coord;
    printf("%s\n", "ENTERED preparing_routine.c/find_old_coordinates :64");

    rows_num = 0;
    counter = 0;
    coord = 0;
    coordinates = (int *)malloc(8 * sizeof(int));
    while (rows_num != 3)
    {
        while (tetromino[counter + 4*rows_num] && counter != 4)
        {
            if (tetromino[counter + 4*rows_num] == '#')
            {
                coordinates[coord] = counter;
                coordinates[coord + 1] = rows_num;
                coord += 2;
            }
            counter ++;
        }
        rows_num++;
    }
    return (coordinates);
}

/*
* function to separate unioned coordinates to x-coordinates array
* and y-coordinates array
*/
int   *parse_to_xy(int coords[8], char xory)
{
    int   iterator;
    int   subcoor;
    int   *oxoy;
    printf("%s\n", "ENTERED preparing_routine.c/parse_to_xy :96");

    iterator = -1;
    subcoor = 0;
    oxoy = (int *)malloc(4 * sizeof(int));
    while (iterator++ < 4)
        oxoy[iterator] = 0;
    iterator = 0;
    //oxoy = [0,0,0,0];
    if (xory == 'y')
        iterator++;
    while (iterator < 8)
    {
        oxoy[subcoor] = coords[iterator];
        subcoor++;
        iterator += 2;
    }
    return (oxoy);
}

/*
* function to find minimum int in the int* array
*/
int     min_in_array(int *numbers)
{
    int     min;
    int     counter;
    printf("%s\n", "ENTERED preparing_routine.c/min_in_array :123");

    counter = 0;
    min = numbers[counter];
    while (numbers[counter])
    {
        if (numbers[counter] < min)
            min = numbers[counter];
        counter++;
    }
    return (min);
}

/*
* moving tetromino to (0;0) spot on the field
* for every x in x-coordinates array: x = x - min(x-coordinates)
* for every y in y-coordinates array: y = y - min(y-coordinates)
*/
int   *find_new_coordinates(int *xory_coords)
{
    int   counter;
    int   min;
    printf("%s\n", "ENTERED preparing_routine.c/find_new_coordinates :145");

    counter = 0;
    min = min_in_array(xory_coords);
    while (counter < 4)
    {
        xory_coords[counter] = xory_coords[counter] - min;
        counter++;
    }
    printf("%s\n", "preparing_routine.c/find_new_coordinates :147");
    return (xory_coords);
}

/*
 * here we read and write just one tetromino to its own element of DDL
 */
int	get_one_tetromino(d_list **new_element, int fd, size_t letter)
{
    char	*tmp_line;
    char 	*main_line;
    int 	counter;
    printf("%s\n", "ENTERED preparing_routine.c/get_one_tetromino :205");

    main_line = "";
    counter = 0;
    // single tetromino string has 4 newlines
    while (counter <= 4)
    {
        if(!(get_next_line(fd, &tmp_line)))
            break ;
        main_line = ft_strjoin(main_line, tmp_line);
        main_line = ft_strjoin(main_line, "\n");
        counter++;
    }
    if (counter < 4)
        return (0);
    (*new_element)->content = ft_strdup(main_line);
    (*new_element)->content_size = letter;
    counter = -1;
    while (counter++ < 4)
    {
        (*new_element)->x_coords[counter] = 0;
        (*new_element)->y_coords[counter] = 0;
    }
    printf("%s\n", "preparing_routine.c :220");
    return (1);
}

/*
 * this funciton takes existing tetromino list and adds to it one by one new elements with written tetrominoes
 */
d_list	*get_tetrominos(int fd)
{
    d_list	*tmp_list;
    d_list  *next_list;
    d_list	*head;
    size_t  letter_num;
    printf("%s\n", "ENTERED preparing_routine.c/get_tetrominos :243");

    letter_num = 65;
    tmp_list = ft_doubly_linked_lstnew("\0", 0);
    head = tmp_list;
    while ((get_one_tetromino(&tmp_list, fd, letter_num)))
    {
        next_list = ft_doubly_linked_lstnew("\0", 0);
        ft_doubly_linked_lstadd_toend(&tmp_list, next_list);
        tmp_list = tmp_list->next;
        letter_num ++;
        printf("%ld\n", letter_num);
    }
    // test printf, never mind
    printf("%s\n", "preparing_routine.c :245");


    return (head);
}

int     reader()
{
    int fd;
    int size;
    if (argc < 2)
        return (-1);

    fd = open(argv[1], O_RDONLY);
    input_data = get_tetrominos(fd);
    return (0);
}