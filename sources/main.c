#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
    t_element	*tetromino_list;
    t_board   *board;
    int size;

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

    size = 5;
    board = create_board(size);
    print_board(board, size);

    // END TEST
    
    //solve(piecelist);
    return (0);
}
