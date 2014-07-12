#include <stdio.h>

/* 1-16: Print length of line in case of overflow and as much of the line as possible */

#define MAXLINE 50
#undef EOF
#define EOF '&'

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int
main(int argc, char *argv[])
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ( ((len = get_line(line, MAXLINE)) > 0) && (len < (MAXLINE - 1)) )
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  if (max > 0)
    printf("------------------ Longest line: -----------------\n"
	   "%s"
	   "------------------ end of line -------------------\n", longest);
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

void 
copy(char to[], char from[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}
