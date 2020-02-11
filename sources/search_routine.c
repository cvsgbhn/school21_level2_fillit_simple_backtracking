#include "../includes/fillit.h"

int   check_other_tetromino(t_element *tetromino, t_board *board, int size)
{
  int num;
  int x;
  int y;

  num = 0;
  x = tetromino->x_coords[num] + tetromino->x_shift;
  y = tetromino->y_coords[num] + tetromino->y_shift;
  while(num < 4 && x < size && y < size && board->board[y][x] == '.')
  {
    num++;
    x = tetromino->x_coords[num] + tetromino->x_shift;
    y = tetromino->y_coords[num] + tetromino->y_shift;
  }
  if (num == 4)
    return(1);
  else
    return(0);
}

char   check_bounds(int size, t_element *tetromino)
{
  int num;
  int x;
  int y;

  num = -1;
  while(num++ < 4)
  {
    x = tetromino->x_coords[num] + tetromino->x_shift;
    y = tetromino->y_coords[num] + tetromino->y_shift;
    if (y > size)
      return('y');
    if (x > size)
      return('x');
  }
  return 'N';
}

void place_tetromino(t_element *tetromino, t_board *board, int flag)
{
  int x;
  int y;
  int num;

  num = 0;
  x = tetromino->x_coords[num] + tetromino->x_shift;
  y = tetromino->y_coords[num] + tetromino->y_shift;
  while (num < 4)
  {
    x = tetromino->x_coords[num] + tetromino->x_shift;
    y = tetromino->y_coords[num] + tetromino->y_shift;
    if (!flag)
      board->board[y][x] = tetromino->letter;
    else
      board->board[y][x] = tetromino->letter;
    num++;
  }
}

int searcher(t_element *tetromino, t_board *board, int b_size)
{
  if (tetromino->next == NULL)
    return(1);
  tetromino->x_shift = 0;
  tetromino->y_shift = 0;
  while(check_bounds(b_size, tetromino) != 'y' && check_bounds(b_size, tetromino) != 'x')
  {
    while(check_bounds(b_size, tetromino) != 'x')
    {
      while(check_other_tetromino(tetromino, board, b_size))
      {
        place_tetromino(tetromino, board, 0);
        printf("try: \n");
        print_board(board, b_size);
        if (searcher(tetromino->next, board, b_size))
          return (1);
        else
          place_tetromino(tetromino, board, 1);
      }
      tetromino->x_shift++;
    }
    tetromino->x_shift = 0;
    tetromino->y_shift++;
  }
  return(0);
}

void search_manager(t_element *tetrolist)
{
  int size;
  t_board *board;

  size = find_field_size(find_tetrominos_number(tetrolist));
  board = create_board(size);
  printf("%s\n", "printed from the manager");
  print_board(board, size);
  while(searcher(tetrolist, board, size) == 0)
  {
    printf("%s\n","resize map");
    size++;
    // free board
    board = create_board(size);
  }
  printf("%s","\n\nHOOORAAAY!!!!\n\n");
  print_board(board, size);
  // free board
}
