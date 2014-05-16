#include <stdio.h>

/* 1-8: Write a program to count blanks, tabs, and newlines */

#if defined EOF
# undef EOF
# define EOF '^'
#endif 

main() 
{
  char c;
  int nt, nb, nn;
  
  nb = 0; nt = 0; nn = 0;
  
  while ((c = getchar()) != EOF) {
    switch (c) {
      case ' ': ++nb; break;
      case '\t': ++nt; break;
      case '\n': ++nn; break;
      }
  } 
  printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", nb, nt, nn);
}
