#include <stdio.h>
#include <math.h>
#include "cs50.h"

long get_number(void);
int get_length(long value);
int get_num_to_last(long number, int place);
int compute_sum(long number, int length);
string define_card_type(long number, int length);

int main(void)
{
  long number = get_number();

  int length = get_length(number);

  if (length < 13)
  {
    printf("INVALID\n");
    return 1;
  }

  int last_digit = compute_sum(number, length);

  if (last_digit != 0)
  {
    printf("INVALID\n");
    return 1;
  }

  string card_type = define_card_type(number, length);
  printf("%s\n", card_type);
  return 0;
}

long get_number(void)
{
  long number;
  do
  {
    number = get_long("Number: ");
  }
  while (number < 0);

  return number;
}

int get_length(long value)
{
  int length = 1;
  while(value > 9)
  {
    length++;
    value /= 10;
  }
  return length;
}

int get_num_to_last(long number, int place)
{
  return number % (long) powl(10, place) / (long) powl(10, place - 1);
}

int compute_sum(long number, int length)
{
  int sum = 0;
  for (int place = 2; place <= length; place += 2)
  {
    int num = get_num_to_last(number, place) * 2;
    sum += num > 9 ? (1 + num % 10) : num;
  }
  for (int place = 1; place <= length; place += 2)
  {
    int num = get_num_to_last(number, place);
    sum += num;
  }
  return sum % 10;
}

string define_card_type(long number, int length)
{
  int first_digit = get_num_to_last(number, length);
  int second_digit = get_num_to_last(number, length - 1);

  if (first_digit == 4 && (length == 16 || length == 13))
  {
    return "VISA";
  }
  else if (first_digit == 3 && length == 15)
  {
    if (second_digit == 4 || second_digit == 7)
    {
      return "AMEX";
    }
  }
  else if (first_digit == 5 && length == 16)
  {
    if (second_digit >= 1 && second_digit <= 5)
    {
      return "MASTERCARD";
    }
  }
  return "INVALID";
}
