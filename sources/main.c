# include "fillit.h"

int		main(int argc, char **argv)
{
    t_piece	*tetromino_list;

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
    solve(piecelist);
    return (0);
}
