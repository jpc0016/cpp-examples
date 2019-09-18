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

void taunt(){
  printf("\nHey, laser lips, your mama was a snow blower.\n");
}

int main(){

  // size_t encodes the size of objects
  // typically used in array indexing and loop counting
  // For more on size_t:
  //    https://en.cppreference.com/w/c/types/size_t



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

  taunt();

  return 0;
}
