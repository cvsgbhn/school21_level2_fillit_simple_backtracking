# include "fillit.h"

/*
 * valid figure
 * input: coords, i think
 */


/*
 * count symbols, strings,, etc.
 * also check if there are only valid symbols
 */
 int valid_symbols(char *tetromino)
 {
   int itr;
   int hash;
   int dots;
   int newline;

   itr = 0;
   hash = 0;
   dots = 0;
   newline = 0;
   while(tetromino[itr])
   {
     if(tetromino[itr]=='#')
        hash++;
     if(tetromino[itr]=='\n' && (itr + 1) % 5 == 0)
        newline++;
     if(tetromino[itr]=='.')
        dots++;
     itr++;
   }
   printf("%s %d %d %d\n", "hash newline dots", hash, newline, dots);
   if (hash != 4 || newline != 4 || dots != 12)
     return(-1);
   return (1);
 }

int valid_figure(char *tetromino, t_element *telement)
{
  //int relations[4];
  int position;
  int cntr;
  int relations;

  cntr = 0;
  position = 0;
  relations = 0;
  while(cntr < 4)
  {
    //relations[cntr] = 0;
    position = telement->x_coords[cntr] + (5 * (telement->y_coords[cntr]) + 1);
    printf("%s %d\n", "position ", position);
    if ((position - 5) > 0 && tetromino[position - 5] == '#')
      relations++;
    if ((position - 1) > 0 && tetromino[position - 1] == '#')
      relations++;
    if ((position + 5) > 0 && tetromino[position + 5] == '#')
      relations++;
    if ((position + 1) > 0 && tetromino[position + 1] == '#')
      relations++;
    cntr++;
  }
  printf("%s %d\n", "RELATIONS TEST: ",relations);
  if (relations < 5 || relations > 8)
    return (-1);
  return (1);
}
