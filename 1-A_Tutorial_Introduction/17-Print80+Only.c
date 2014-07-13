#include <stdio.h>

/* 1-17: Print all input lines that are longer than 80 characters */

#define MAXLINE 512
#define PRINT_THRESHOLD 80
#undef EOF
#define EOF '&'

int get_line (char s[], int lim);

int
main(int argc, char *argv[])
{
  int len;
  int max;
  char line[MAXLINE];

  while ( ((len = get_line(line, MAXLINE)) > 0) && (len < (MAXLINE - 1)) ) {
    if (len >= PRINT_THRESHOLD) {
      printf ("\nLine longer than %d characters! Print line below:\n"
	      "%s"
	      "---------------------------------------------------\n", 
	      PRINT_THRESHOLD, line);
    }
  }
  return 0;
}

int 
get_line(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!= '\n'; ++i)
      s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  } 
 
  s[i] = '\0';

  if (i >= (lim-1)) {
  printf ("Overflow detected, line is %d characters long\n", (i+1));
  printf("--------------------- On line: -------------------\n"
	 "%s\n"
	 "------------------- end of line ------------------\n", s);
  }
  
  return i;
}
