#include <stdio.h>
#include <cs50.h>

int get_number(int min, string title);
int calculate_years(int start, int end);

int main (void)
{
  // Prompt for start size
  int start_size = get_number(9, "Start");

  // Prompt for end size
  int end_size = get_number(start_size, "End");


  // Calculate number of years until we reach threshold
  int years = calculate_years(start_size, end_size);

  // Print number of years
  printf("Years: %i", years);
}

int get_number(int min, string title)
{
  int number;
  do
  {
    number = get_int("%s size: ", title);
  }
  while (number < min);

  return number;
}

int calculate_years(int start, int end)
{
  int years = 0;

  while (start < end)
  {
    start += (start / 3) - (start / 4);
    years++;
  }
  
  return years;
}