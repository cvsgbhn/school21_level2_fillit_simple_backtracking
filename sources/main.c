#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
    t_element	*tetromino_list;
    int         tetronum;

    if (argc != 2)
    {
        ft_putstr("error: provide source_file\n");
        return (1);
    }
    if ((tetromino_list = reader(argv[1])) == NULL)
    {
        ft_putstr("error\n");
        return (1);
    }
    tetronum = find_tetrominos_number(tetromino_list);
    if (tetronum == 0 || tetronum > 26)
    {
        printf("error\n");
        return (1);
    }
    search_manager(tetromino_list);
    // free tetromino_list
    return (0);
}
