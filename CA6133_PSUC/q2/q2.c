#include <stdio.h>

int main() {
  float fahrenheit, centigrade;

  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit);

  centigrade = 5.0/9.0 * (fahrenheit - 32);

  printf("Temperature in Centigrade = %.2f\n", centigrade);

  centigrade = fahrenheit = 0;

  printf("Enter temperature in Centigrade: ");
  scanf("%f", &centigrade);

  fahrenheit = 9.0/5.0 * centigrade + 32;

  printf("Temperature in Fahrenheit = %.2f\n", fahrenheit);

  return 0;
}
