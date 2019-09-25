/*
* Ch2 Example
*
* destructors.cpp
*
* Demonstrating destructors and more braced initializers; pages 64 - 65
*
*/

#include <cstdio>

// Can use braced initializers when initializing members of a class
// Note: parentheses cannot be used in place of braces
struct JohanVanDerSmut {
  bool gold = true;
  int year_of_smelting_accident = { 1970 };
  char key_location[8] = { "x-rated" };
};


// Destructor is invoked as a cleanup function.  It is called with '~' and takes
// no arguments
// Defining destructors are optional
struct Earth {
  ~Earth() {
    printf("Making way for hyperspace bypass");
  }

};


int main() {
  return 0;
}
