#include <stdio.h>
#include <stdbool.h>

/* 1-14: Print a histogram of the frequencies of diferent characters in its input */

#if defined EOF
# undef EOF
# define EOF '^'
#endif

bool checkChar(char c);
unsigned char getIndex(char c);

unsigned char numberOfDifferentChars = 0;
unsigned char characters[256][2];

main() 
{
  char c;
  int max_value;
  int i, j;  

  while ( (c = getchar()) != EOF) {
    if (!checkChar(c)) {
      characters[numberOfDifferentChars++][0] = c;
      characters[getIndex(c)][1]++;
    } else
      characters[getIndex(c)][1]++;
  }

  // Horizontal histogram
  printf("\nHORIZONTAL HISTOGRAM\n");
  for (i = 0; i < numberOfDifferentChars; i++) {
    printf("%c ", characters[i][0]);
    for (j = 1; j <= characters[i][1]; j++)
      printf("|");
    printf("\n");
  }
  
  // Vertical histogram
  // Find max
  printf("\nVERTICAL HISTOGRAM\n");
  max_value = 0;
  for (i = 0; i < numberOfDifferentChars; i++) {
    if (characters[i][1] > max_value)
      max_value = characters[i][1];
  }
  
  // Draw histogram
  while (max_value > 0) {
    for (i = 0; i < numberOfDifferentChars; i++) {
      if (characters[i][1] >= max_value)
	printf("#");
      else
	printf(" ");
      printf(" ");
    }
    max_value--;
    printf("\n");
  }

  // Write bottom legend
  for (i = 0; i < numberOfDifferentChars; i++)
    printf("%c ", characters[i][0]);
  printf("\n");
}

// Returns true if c is already in the array, false if it is not.
bool checkChar(char c) 
{
  int i;
  for (i = 0; i < numberOfDifferentChars; i++) {
    if (characters[i][0] == c)
      return true;
  }
  return false;
}

// Returns index of c in the array
unsigned char getIndex(char c) 
{
  int i;
  for (i = 0; i < numberOfDifferentChars; i++) {
    if (characters[i][0] == c)
      return i;
  }
  return 255;
}
