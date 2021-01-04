#include <stdio.h>
#include "cs50.h"

int main (void)
{
  int height;
  do
  {
    height = get_int("Height: ");
  }
  while (height < 1 || height > 8);
  
  for (int row = 0; row < height; row++)
  {
    for (int dot = 0; dot < height - (row + 1); dot++)
    {
      printf(".");
    }
    for (int hash = 0; hash < row + 1; hash++)
    {
      printf("#");
    }
    printf("\n");
  }
}

// Output:
// .......#
// ......##
// .....###
// ....####
// ...#####
// ..######
// .#######
// ########
