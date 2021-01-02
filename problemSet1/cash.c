#include <stdio.h>
#include <math.h>
#include "cs50.h"

float getDollars(void);
int countCoins(int cents);

int main (void)
{
  float dollars = getDollars();

  int cents = round(dollars * 100);

  int coins = countCoins(cents);

  printf("%i coins\n", coins);
}

float getDollars(void)
{
  float dollars;
  do
  {
    dollars = get_float("Change owed: ");
  }
  while (dollars < 0);

  return dollars;
}

int countCoins(int cents)
{
  int coins = 0;

  do
  {
    if (cents >= 25)
    {
      cents -= 25;
      coins++;
    } 
    else if (cents >= 10)
    {
      cents -= 10;
      coins++;
    } 
    else if (cents >= 5)
    {
      cents -= 5;
      coins++;
    } 
    else
    {
      cents -= 1;
      coins++;
    }
  }
  while (cents != 0);

  return coins;
}
