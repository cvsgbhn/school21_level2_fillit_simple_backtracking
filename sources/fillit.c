#include "../includes/fillit.h"

void    test_print_structure(t_element *tetromino)
{
    int counter = 0;
    printf("%s\n", "TEST");

    printf("%s %c\n", "tetromino letter", tetromino->letter);
    while (counter < 4)
    {
        printf("%s %d\n", "x", tetromino->x_coords[counter]);
        printf("%s %d\n", "y", tetromino->y_coords[counter]);
        counter++;
    }
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
    printf("%s%s\n", "tetromino:\n", tetromino);
    while (rows_num != 4)
    {
        printf("%s\n", "old coords :35");
        counter = 0;
        while (tetromino[counter + 5*rows_num] && counter != 5)
        {
            if (tetromino[counter + 5*rows_num] == '#')
            {
                printf("%d %s\n", tetromino[counter + 5*rows_num], "old coords :40");
                coordinates[coord] = counter;
                coordinates[coord + 1] = rows_num;
                coord += 2;
            }
            counter ++;
        }
        rows_num++;
    }
    counter = 0;
    while (counter < 8)
    {
        printf("%s %d\n", "all coordinates", coordinates[counter]);
        counter++;
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
void   find_new_coordinates(int tetro_coords[4], int xory_coords[4])
{
    int   counter;
    int   min;
    printf("%s\n", "ENTERED preparing_routine.c/find_new_coordinates :145");

    counter = 0;
    min = min_in_array(xory_coords);
    while (counter < 4)
    {
        tetro_coords[counter] = xory_coords[counter] - min;
        counter++;
    }
    printf("%s\n", "END OF find_new_coordinates");
}

/*
 * here we read and write just one tetromino to its own element of DDL
 */
int	get_one_tetromino(t_element *new_element, int fd, char letter)
{
    char	*tmp_line;
    char 	*main_line;
    int 	counter;
    int     *full_coords;
    printf("%s\n", "ENTERED preparing_routine.c/get_one_tetromino :205");

    main_line = "";
    counter = 0;
    // single tetromino string has 4 newlines
    while (counter <= 3)
    {
        if(!(get_next_line(fd, &tmp_line)))
            break ;
        main_line = ft_strjoin(main_line, tmp_line);
        main_line = ft_strjoin(main_line, "\n");
        counter++;
    }
    get_next_line(fd, &tmp_line);
    if (counter < 3)
        return (0);
    // check main line aka tetromino here !!!
    new_element->letter = letter;
    // get coords!!!
    full_coords = (find_old_coordinates(main_line));
    find_new_coordinates(new_element->x_coords, (parse_to_xy(full_coords, 'x')));
    find_new_coordinates(new_element->y_coords, (parse_to_xy(full_coords, 'y')));
    counter = 0;
    while (counter < 4)
    {
        printf("%s %d\n", "aa_x", new_element->x_coords[counter]);
        printf("%s %d\n", "aa_y", new_element->y_coords[counter]);
        counter++;
    }
    if((valid_figure(main_line, full_coords)==-1) || (valid_symbols(main_line)==-1))
        return(-1);
    free(main_line);
    return (1);
}


/*
 * this funciton takes existing tetromino list and adds to it one by one new elements with written tetrominoes
 */
t_element	*get_tetrominos(int fd)
{
    t_element	*tmp_tetro;
    t_element  *next_tetro;
    t_element	*head;
    char  letter;
    int   valid;
    printf("%s\n", "ENTERED ");

    letter = 65;
    tmp_tetro = create_t_element(letter);
    head = tmp_tetro;
    while (((valid = get_one_tetromino(tmp_tetro, fd, letter++)) == 1))
    {
        next_tetro = create_t_element(letter);
        add_last_t_element(&tmp_tetro, next_tetro);
        test_print_structure(tmp_tetro);
        tmp_tetro = tmp_tetro->next;
    }
    if (valid == -1)
      return((head = NULL));
    test_print_structure(tmp_tetro);
    return (head);
}

t_element     *reader(char *file)
{
    int fd;
    t_element *input_data;

    fd = open(file, O_RDONLY);
    if((input_data = get_tetrominos(fd)))
      return (input_data);
    else
      return NULL;
}
