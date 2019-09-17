/*
* Ch2 Example
*
* boolean.cpp
*
* Demonstrating boolean types, comparisons, and logical operators with
* format specifiers; pages 39 - 40
*/

#include <cstdio>

int main(){

  // Listing 2-5
  bool b1 = true;
  bool b2 = false;

  // No format specifier for bool but can use int specifier (%d) to show 1 for true and 0 for false.
  printf("%d %d\n\n", b1, b2);


  // Comparison operators; Listing 2-6
  printf("7 == 7: %d\n", 7 == 7);
  printf("7 != 7: %d\n", 7 != 7);
  printf("10 > 20: %d\n", 10 > 20);
  printf("10 >= 20: %d\n", 10 >= 20);
  printf("10 < 20: %d\n", 10 < 20);
  printf("10 <= 20: %d\n\n", 10 < 20);


  // Logical Operators; Listing 2-7
  // AND = &&
  // OR = ||
  printf("NOT true: %d\n", !b1);
  printf("true AND false: %d\n", b1 && b2);
  printf("true AND NOT false: %d\n", b1 && !b2);
  printf("true OR false: %d\n", b1 || b2);
  printf("false OR false: %d\n", b2 || b2);

  return 0;
}
