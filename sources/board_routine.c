#include "../includes/fillit.h"

t_board *create_board(int size)
{
  t_board *board;
  int counter;

  counter = 0;
  board = (t_board *)malloc(sizeof(t_board));
  printf("%s\n", "mallocked t_board");
  board->board = (char **)malloc(sizeof(char *) * size);
  printf("%s\n", "mallocked t_board->board");
  while(counter < size)
  {
    board->board[counter] = (char *)malloc(sizeof(char) * size);
    printf("%s %d\n", "mallocked row number ", counter);
    ft_memset(board->board[counter], '.', size);
    printf("%s\n", "filled row with dots");
    counter++;
  }
  return (board);
}

void print_board(t_board *board, int size)
{
  int counter;

  counter = 0;
  while(counter < size)
  {
    ft_putendl(board->board[counter]);
    counter++;
  }
}

void    free_board(t_board *board, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        printf("%s\n", "free row of board");
        ft_memdel((void **)&(board->board[i]));
        i++;
    }
    ft_memdel((void **)&(board->board));
    ft_memdel((void **)&board);
}
