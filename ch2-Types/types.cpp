/*
* Ch2 Example
*
* types.cpp
*
* Demonstrating number types and INTEGER format specifiers; page 33
*/

#include <cstdio>

int main(){

  // Listing 2-1
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

  return 0;
}
