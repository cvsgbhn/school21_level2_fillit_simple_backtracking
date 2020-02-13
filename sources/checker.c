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
   int all;
   int hashes;

   all = 0;
   hashes = 0;
   while(tetromino[all])
   {
     if(tetromino[all] == '#')
      hashes++;
     all++;
   }
   if (ft_strlen(tetromino) != 20)
    printf("INVALID by len");
   printf("%d %d\n", hashes, all);
   ft_putchar('Z');
   ft_putchar(tetromino[all]);
   if (tetromino[all] == '\n')
    all++;
   if(hashes != 4)
    return(-1);
   return(1);
 }

 /*
  * check length - oh my god, I have that function!!!!
  */
