/*
Ch1 Example

conditionals.cpp

Conditional Statements; page 15
*/

#include <cstdio>

int main() {

  // Basic comparison operators. No output is produced but creates 6 warnings
  // due to unused comparison results. a.out still runs.

  int x = 0;
  42 == x;  // Equality
  42 != x;  // Inequality
  100 > x;  // Greater than
  123 >= x; // Greater than or equal to
  -10 < x;  // Less than
  -99 <= x; // Less than or equal to

  return 0;
}
