/*
* Ch2 Example
*
* special-types.cpp
*
* Demonstrating std::byte, size_t, and void types with format specifiers; pages 41 - 42
*/

// new library cstddef for size_t types
// will sometimes see size_t as 'std::size_t'
#include <cstdio>
#include <cstddef>

int main(){

  // size_t encodes the size of objects
  // %zd for decimal representations
  // %zx for hex representations
  // sizeof() returns size in bytes
  size_t size_c = sizeof(char);
  printf("char: %zd\n", size_c);
  size_t size_s = sizeof(short);
  printf("short: %zd\n", size_s);
  size_t size_i = sizeof(int);
  printf("int: %zd\n", size_i);
  size_t size_l = sizeof(long);
  printf("long: %zd\n", size_l);
  size_t size_ll = sizeof(long long);
  printf("long long: %zd\n", size_ll);


  return 0;
}
