#include <stdio.h>

/* 1-20: Replace tabs by BLANK_COLUMN_NUM blanks in every input line */

#define MAXLINE 512
#undef EOF
#define EOF '&'

#define SIZEOF_TAB 8

int tabsNum = 0;
int spacesNum = 0;

int get_line(char line[], int maxline);

int
main(int argc, char *argv[])
{
  int len;
  int max;
  char line[MAXLINE];

  while ( ((len = get_line(line, MAXLINE)) > 0) && (len < (MAXLINE - 1)) ) {
    printf ("\nNew line -- Entabed:\n"
	    "%s\n"
	    "---------------------------------------------------\n", 
	    line);
  }
  return 0;
}

int 
get_line (char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!= '\n'; ++i) {
    if (c == ' '
  }

  /* ! Do not include end of line character for cleaner output ! */
  
  s[i] = '\0';

  if (i >= (lim-1))
    printf ("Overflow detected, line is %d characters long\n", (i+1));
  
  return i;
}
