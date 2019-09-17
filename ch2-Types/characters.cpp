/*
* Ch2 Example
*
* characters.cpp
*
* Demonstrating char types and format specifiers; page 38
*/

#include <cstdio>

int main(){

  // char = 1 byte
  // char16_t = 2 bytes
  // char32_t = 4 bytes
  // wchar_t = holds unicode character sets
  // Format specifier is %c for char or %lc for wchar_t
  char x = 'M';
  wchar_t y = L'Z';

  printf("Windows binaries start with %c%lc.\n", x, y);

  return 0;
}
