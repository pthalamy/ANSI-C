#include <stdio.h>

/* 1-15: print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;  
   using a function for conversion */

float convertToCelsius(float fahr);

main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("---------- Fahrenheit-Celsius Table -----------\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = convertToCelsius(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

float convertToCelsius(float fahr)
{
  return ((5.0/9.0) * (fahr-32.0));
}
