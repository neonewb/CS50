#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "cs50.h"
int is_invalid(int argNum, string key);
void print_ciphertext(string plaintext, string key);

int main(int argc, string argv[])
{
  if (is_invalid(argc, argv[1]))
  {
    return 1;
  }

  string plaintext = get_string("plaintext: ");

  print_ciphertext(plaintext, argv[1]);
}

int is_invalid(int argNum, string key)
{
  if (argNum != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  int length = strlen(key);

  if (length != 26)
  {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  for (int i = 0; i < length; i++)
  {
    if (!isalpha(key[i]))
    {
      printf("Key must only contain alphabetic characters.\n");
      return 1;
    }
  }
  return 0;
}

void print_ciphertext(string plaintext, string key)
{
  int length = strlen(plaintext);

  printf("ciphertext: ");
  for (int i = 0; i < length; i++)
  {
    if (isalpha(plaintext[i]))
    {
      if (isupper(plaintext[i]))
      {
        printf("%c", toupper(key[(plaintext[i] - 65)]));
      }
      else
      {
        printf("%c", tolower(key[(plaintext[i] - 97)]));
      }
    } 
    else
    {
      printf("%c", plaintext[i]);
    }
  }
  printf("\n");
}
