#include <stdio.h>

/* 1-9: Write to copy its input to its outpus, replacing each
 string of one or moreblanks by a single blank */

#if defined EOF
# undef EOF
# define EOF '^'
#endif

main() 
{
  char c, prev_c;
  
  while ((c = getchar()) != EOF) {
    if ( !((prev_c == ' ')&&(c == ' ')) )
      putchar(c);

    prev_c = c;
  } 
}
