#include <stdio.h>

/* 1-12: Write a program that prints its input one word per line */

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

#if defined EOF
# undef EOF
# define EOF '^'
#endif

main() 
{
  char c;
  
  while ( (c = getchar()) != EOF) {
    if (c == '\t' || c == ' ')
      putchar('\n');
    else
      putchar(c);
  }
}
