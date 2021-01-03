#include <stdio.h>
#include "cs50.h"

void print_hash(int number);
void print_space(int number);

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
    print_space(height - row);
    print_hash(row);
    print_space(2);
    print_hash(row);
    printf("\n");
  }
}

void print_hash(int number)
{
  for (int hash = 0; hash < number; hash++)
  {
    printf("#");
  }
}

void print_space(int number)
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
