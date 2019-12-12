/*
* CH4 Example
*
* copy-semantics.cpp
*
* cover nuances while copying stuff; pages 115-116
* BY VALUE = a copy of data
*
* Listing 4-23
*
*/

#include <cstdio>
// #include <cstring>
// #include <stdexcept>

int add_one_to(int x){
  /* argument x is taken BY VALUE
  modification of x is isolated by caller (line 27) so original is unaffected
  */
  x++;
  return x;
}

int main() {
  auto original = 1;
  auto result = add_one_to(original);
  printf("Original: %d; Result: %d\n", original, result);
  return 0;
}
