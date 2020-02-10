#include "../includes/fillit.h"

char **create_board(int size)
{
  char *board[size];

  board = (char *)malloc(size * sizeof(char[size][size]));
  return (&board);
}
