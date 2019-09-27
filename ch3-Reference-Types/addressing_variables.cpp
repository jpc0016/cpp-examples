/*
* Ch3 Example
*
* addressing_variables.cpp
*
* Demonstrate pointers and addressing variables; pages 68 - 71
* Gettysburg Address
*/

#include <cstdio>

int main() {

  // '&' = address-of operator
  // This is used to initialize a pointer so it "points to" the corresponding variable

  // Equivalent to int gettysburg = 0;
  // Source: https://stackoverflow.com/questions/23120856/use-of-curly-brackets-braces-around-a-variable-c
  int gettysburg{};
  printf("gettysburg: %d\n", gettysburg);

  // Declare pointer to gettysburg's address
  int *gettysburg_address = &gettysburg;
  // Asterisk not used when printing a pointer; asterisk is used later when dereferencing the pointer;
  // however, it requires different format specifier than %p
  // Output of gettysburg_address will be different every time the program is compiled due to Address Space
  // Layout Randomization (ASLR)
  printf("&gettysburg: %p\n", gettysburg_address);
  printf("gettysburg accessed by dereferencing pointer: %d\n", *gettysburg_address);


  // '*' = dereference operator
  // Since gettysburg_address was initialized as a pointer, its contents can be accessed like so
  // *gettysburg_address
  // Can write a value into gettysburg using gettysburg_address like so
  *gettysburg_address = 17325;
  printf("\nThe updated value of gettysburg is %d\n", *gettysburg_address);
  printf("&gettysburg: %p\n", gettysburg_address);


  return 0;
}
