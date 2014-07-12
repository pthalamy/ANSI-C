#include <stdio.h>

/* 1-19: Write a program to reverse a each character string */

#define MAXLINE 512
#define PRINT_THRESHOLD 80
#undef EOF
#define EOF '&'

int get_line(char line[], int maxline);
void reverse(char s[]);

int
main(int argc, char *argv[])
{
  int len;
  int max;
  char line[MAXLINE];

  while ( ((len = get_line(line, MAXLINE)) > 0) && (len < (MAXLINE - 1)) ) {
    reverse (line);
    printf ("\nNew line -- Reversed:\n"
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
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!= '\n'; ++i)
      s[i] = c;

  /* ! Do not include end of line character for cleaner output ! */
  
  s[i] = '\0';

  if (i >= (lim-1))
    printf ("Overflow detected, line is %d characters long\n", (i+1));
  
  return i;
}

void 
reverse (char s[])
{
  int i, length;
  char tmp[MAXLINE];
  
  /* Get length of string and copy to tmp */
  for (i = 0; s[i] != '\0'; ++i)
    tmp[i] = s[i];

  /* Store length */
  length = i;

  /* Reverse string */
  for (i = 0; i < length; ++i)
    s[i] = tmp[(length - i) - 1];
  
  /* Add end of string character */
  s[i] = '\0';
}
