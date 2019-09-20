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


  // Printing alphabet. Loop stops at 26 because alphabet[] contains NULL byte
  // for 0 to 25, stops at 26
  char alphabet[27];
  for(size_t i=0; i<26; i++){

    // Start at decimal offset 97 (0x61) which is 'a'
    alphabet[i] = i + 97;
  }
  // Set NULL byte
  alphabet[26] = 0;
  printf("%s\n", alphabet);

  for(size_t i = 0; i < 26; i++){

    // Start at decimal offset 65 (0x41) which is 'A'
    alphabet[i] = i + 65;
  }

  // Set NULL byte
  alphabet[26] = 0;
  printf("%s\n", alphabet);

  return 0;
}
