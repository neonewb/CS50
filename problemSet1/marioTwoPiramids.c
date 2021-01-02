#include <stdio.h>
#include "cs50.h"

void printHash(int number);
void printSpace(int number);

int main (void)
{
  int height;
  do
  {
    height = get_int("Height: ");
  }
  while (height < 1 || height > 8);
  
  for (int row = 1; row <= height; row++)
  {
    printSpace(height - row);
    printHash(row);
    printSpace(2);
    printHash(row);
    printf("\n");
  }
}

void printHash(int number)
{
  for (int hash = 0; hash < number; hash++)
  {
    printf("#");
  }
}

void printSpace(int number)
{
  for (int space = 0; space < number; space++)
  {
    printf(" ");
  }
}

// Output:
// Height: 8
//        #  #
//       ##  ##
//      ###  ###
//     ####  ####
//    #####  #####
//   ######  ######
//  #######  #######
// ########  ########