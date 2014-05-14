#include <stdio.h>

/* 1-13: Write a program to print a histogram of the lenghts of words in its input */

#if defined EOF
# undef EOF
# define EOF '^'
#endif

#define NUM_LETTERS_MAX 15

main() 
{
  char c;
  int current_word_count = 0;
  int num_letters[NUM_LETTERS_MAX];
  int max_value;

  int i, j;  
  for (i = 0; i < NUM_LETTERS_MAX; i++)
    num_letters[i] = 0;

  while ( (c = getchar()) != EOF) {
    if (c == '\t' || c == ' ' || c == '\n') {
      if (current_word_count != 0)
	num_letters[current_word_count-1]++;
      current_word_count = 0;
    } else
      current_word_count++;
  }
  
  // Horizontal histogram
  printf("\nHORIZONTAL HISTOGRAM\n");
  for (i = 0; i < NUM_LETTERS_MAX; i++) {
    printf("%d", i+1);
    if (i < 9) printf(" ");
    for (j = 1; j <= num_letters[i]; j++)
      printf("|");
    printf("\n");
  }
  
  // Vertical histogram
  // Find max
  printf("\nVERTICAL HISTOGRAM\n");
  max_value = 0;
  for (i = 0; i < NUM_LETTERS_MAX; i++) {
    if (num_letters[i] > max_value)
      max_value = num_letters[i];
  }
  
  // Draw histogram
  while (max_value > 0) {
    for (i = 0; i < NUM_LETTERS_MAX; i++) {
      if (num_letters[i] >= max_value)
	printf("#");
      else
	printf(" ");
      printf(" ");
    }
    max_value--;
    printf("\n");
  }

  // Write legend
  for (i = 0; i < NUM_LETTERS_MAX; i++)
    printf("%d ", i+1);
  printf("\n");
}
