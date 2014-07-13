#include <stdio.h>

/* 1-21: Replace blanks with as many tabs and spaces as possible */

#define MAXLINE 512
#undef EOF
#define EOF '&'

#define TABSTOP 8

int tabCount = 0;
int spaceCount = 0;

int get_line (char s[], int lim);

int
main(int argc, char *argv[])
{
  int len;
  int max;
  char line[MAXLINE];

  while ( ((len = get_line(line, MAXLINE)) > 0) && (len < (MAXLINE - 1)) ) {
    printf ("\nNew line -- Entabed with %d tabs and %d spaces:\n"
	    "%s\n"
	    "---------------------------------------------------\n", 
	    tabCount, spaceCount, line);
    tabCount = 0;
    spaceCount = 0;
  }
  return 0;
}

int 
get_line (char s[], int lim)
{
  int c, i;
  int blankCount;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == ' ' || c == '\t') {
      /* Get number of blanks until next character */
      blankCount = 0;
     
      if (c == ' ')
	++blankCount;
      else
	blankCount += TABSTOP;
	
      while ((c = getchar()) == ' ' || c == '\t') {
	if (c == ' ')
	  ++blankCount;
	else 
	  blankCount += TABSTOP;
      }
      /* Fill it with as less tabs and spaces as possible */
      if (!(blankCount % TABSTOP)) { 
	/* If space can be filled only with tabs, do so */
	int x;
	for (x = 0; x < blankCount; x += TABSTOP) {
	  s[i++] = '\t';
	  ++tabCount;
	}
	/* Store non blank char */
	s[i] = c;
      } else {
	int x;
	/* Fill with as many tabs as possible */
	for (x = 0; x < (blankCount - (blankCount % TABSTOP)); x += TABSTOP) {
	  s[++i] = '\t';
	  ++tabCount;
	}
	/* Fill the rest with spaces */
	for (x = 0; x < (blankCount % TABSTOP); ++x) {
	  s[++i] = ' ';
	  ++spaceCount;
	}
	/* Store non blank char */
	s[i] = c;
      }
    
      if (s[i] == '\n')
	break;

    } else 
      s[i] = c;
  }
    
    /* ! Do not include end of line character for cleaner output ! */
    
    s[i] = '\0';
    
    if (i >= (lim-1))
      printf ("Overflow detected, line is %d characters long\n", (i+1));
  
    return i;
}
