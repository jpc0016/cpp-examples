/*
* Ch3 Example
*
* addressing_variables.cpp
*
* Demonstrate pointers and addressing variables; pages 68 - 69
*
*/

#include <cstdio>

int main() {

  // '&' = address-of operator
  // This is used to initialize a pointer so it "points to" the corresponding variable

  // equivalent to int gettysburg = 0;
  // source: https://stackoverflow.com/questions/23120856/use-of-curly-brackets-braces-around-a-variable-c
  int gettysburg{};
  printf("gettysburg: %d\n", gettysburg);

  // declare pointer to gettysburg's address
  int *gettysburg_address = &gettysburg;
  // asterisk not required when printing a pointer
  printf("&gettysburg: %p\n", gettysburg_address);


  return 0;
}
