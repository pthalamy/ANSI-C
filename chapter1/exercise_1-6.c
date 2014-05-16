#include <stdio.h>

/* 1-6: Verify that getchar() != EOF is 0 or 1 */

#ifdef EOF
# undef EOF
# define EOF '^'
#endif

main() 
{
  int c;
  char notEOF;

  while (notEOF = ((c = getchar()) != EOF)) 
    printf("!isEOF: %d\n", notEOF);
  
  printf("!isEOF: %d\n", notEOF);
}
