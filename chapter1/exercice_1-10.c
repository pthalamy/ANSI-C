#include <stdio.h>

/* 1-10: Write to copy its input to its outpus, replacing each
 tab by \t, each backspace by \bn each backslash by \\. This makes tabs and backspaces visible in an unambiguous way */

#if defined EOF
# undef EOF
# define EOF '^'
#endif

main() 
{
  char c;
  
  while ((c = getchar()) != EOF) {
    switch (c) {
    case '\t': printf("\t"); break;
    case '\b': printf("\b"); break;
    case '\\': printf("\\"); break;
    default: putchar(c); break;
    }
  } 
}
