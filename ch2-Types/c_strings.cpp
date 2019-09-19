/*
* Ch2 Example
*
* c_strings.cpp
*
* Demonstrating C-style strings; pages 46 - 49
* A C-style string has a null byte at the end to indicate end of string.  Can
* store strings in arrays of character types.
*/

#include <cstdio>
#include <cwchar>

int main(){

  // These are string literals
  char english[] = "a house of gold.";
  char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

  // Format specifier for narrow strings is '%s'
  // Can use strings with format specifiers like in Python
  printf("A book holds %s\n", english);

  // Printing unicode characters is more complicated.  Use wprintf()
  // from <cwchar>
  // wprintf(L"%s\n", chinese);

  // Can place string literals on multiple lines
  char house[] = "a "
    "house "
    "of "
    "gold.\n";

  printf("A book holds a %s", house);

  return 0;
}
