#include <stdio.h>

/* print Celsius-Fahrenheit table for celsius = -17.8, -6.7, ..., 148.9; floating point conversion */

main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = -17.8;
  upper = 148.9;
  step = 11.1;

  printf("---------- Celsius-Fahrenheit Table -----------\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = ((9.0/5.0) * celsius) + 32.0;
    printf("%6.1f %3.0f\n", celsius, fahr);
    celsius += step;
  }
}
