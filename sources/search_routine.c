#include "../includes/fillit.h"

int searcher(t_element *tetromino, t_board *board, int b_size)
{}

void search_manager(t_element *tetrolist)
{
  int size;

  size = find_field_size(find_tetrominos_number(tetrolist));
  board = create_board(size);
  print_board(board, size);
  
}
