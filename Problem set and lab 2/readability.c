#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>
int compute_index(string text);
int count_letters(string text, int length);
int count_words(string text, int length);
int count_sentences(string text, int length);

int main(void)
{
  string text = get_string("Text: ");

  int index = compute_index(text);

  index > 16
  ? printf("Grade 16+\n")
  : index < 0
  ? printf("Before Grade 1\n")
  : printf("Grade %i\n", index);
}

int compute_index(string text)
{
  int length = strlen(text);

  int letters = count_letters(text, length);

  int words = count_words(text, length);

  int sentences = count_sentences(text, length);

  float L = 100.0 / (float) words * (float) letters;
  float S = 100.0 / (float) words * (float) sentences;

  double index = 0.0588 * L - 0.296 * S - 15.8;
  return (int) round(index);
}

int count_letters(string text, int length)
{
  int letters = 0;
  for (int i = 0; i < length; i++)
  {
    if (isalpha(text[i]))
    {
      letters++;
    }
  }
  return letters;
}

int count_words(string text, int length)
{
  int words = 1;
  for (int i = 0; i < length; i++)
  {
    if (isspace(text[i]))
    {
      words++;
    }
  }
  return words;
}

int count_sentences(string text, int length)
{
  int sentences = 0;
  for (int i = 0; i < length; i++)
  {
    if (text[i] == 33 || text[i] == 46 || text[i] == 63)
    {
      sentences++;
    }
  }
  return sentences;
}
