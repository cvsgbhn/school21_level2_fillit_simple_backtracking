# include "../includes/fillit.h"
/*
* find int square root
*/
int sqrt_root(int number)
{
  int   root;
  int   result;
  printf("ENTERED basic_calculations.c/sqrt_root :28");

  root = 1;
  result = 1;
  if (number == 0 || number == 1)
  return number;
  while (result <= number)
  {
    root++;
    result = root * root;
  }
  return root;
}

/*
* find size of the board
*/
int find_field_size(int tetro_num)
{
    int     size;
    printf("ENTERED basic_calculations.c/find_field_size :48");

    size = sqrt_root(tetro_num * 4);
    return size;
}

/*
 * find length of tetromino list
 */
int   find_tetrominos_number(t_element *tetrolist)
{
  int elements;

  elements = 0;
  while(tetrolist->next != NULL)
  {
    tetrolist = tetrolist->next;
    elements++;
  }
  return elements;
}
