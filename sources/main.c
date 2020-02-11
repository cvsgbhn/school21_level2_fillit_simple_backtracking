#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
    t_element	*tetromino_list;

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
    // TEST:

    search_manager(tetromino_list);

    // END TEST

    //search_manager(tetromino_list);
    // free tetromino_list
    return (0);
}
