/*
* Ch2 Example
*
* types.cpp
*
* Demonstrating number types and format specifiers; pages 33 - 36
*/

#include <cstdio>

int main(){

  // Listing 2-1
  // Integer format specifiers
  unsigned short a = 0b10101010;
  printf("%hu\n", a);

  int b = 0123;
  printf("%d\n", b);

  unsigned long long c = 0xFFFFFFFFFFFFFFFF;
  printf("%llu\n", c);

  // Listing 2-2
  unsigned int d = 3669732608;
  printf("Yabba %x!\n", d);

  unsigned int e = 69;
  printf("There are %u,%o leaves here.\n", e, e);


  // Demonstrate floating point specifiers
  // Can use scientific notation in literals
  double plancks_constant = 6.62607004e-34;
  printf("Planck's Constant: %lf or %le or %lg\n", plancks_constant, plancks_constant, plancks_constant);

  // Listing 2-3
  double an = 6.0221409e23;
  printf("Avogadro's number:  %le %lf %lg\n", an, an, an);

  // %e = scientific notation
  // %f = float specifier
  // %g = printf decides either %e or %f; whichever is more compact
  float hp = 9.75;
  printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp);

  return 0;
}
