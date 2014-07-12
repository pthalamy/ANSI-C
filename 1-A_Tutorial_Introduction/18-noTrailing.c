#include <stdio.h>

/* 1-18: Remove trailing blanks and tabs from each line of input */

#define MAXLINE 512
#undef EOF
#define EOF '&'

int get_line(char line[], int maxline);
void removeTrailing(char line[], int length);

int
main(int argc, char *argv[])
{
  int len;
  int max;
  char line[MAXLINE];

  while ( ((len = get_line(line, MAXLINE)) > 0) && (len < (MAXLINE - 1)) ) {
    removeTrailing (line, len);
    printf ("\nNew line -- Trailing removed:\n"
	    "%s|||| END OF LINE\n"
	    "---------------------------------------------------\n", 
	    line);
  }
  return 0;
}

int 
get_line(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!= '\n'; ++i)
      s[i] = c;
 
  s[i] = '\0';

  if (i >= (lim-1))
    printf ("Overflow detected, line is %d characters long\n", (i+1));
  
  return i;
}

void 
removeTrailing(char line[], int length)
{
  int i;
  for (i = length-1; line[i] == ' ' ||  line[i] == '\t'; --i)
    line[i] = '\0'; 
}
