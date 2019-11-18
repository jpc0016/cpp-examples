/*
* CH4 Example
*
* exceptions.cpp
*
* Handling exceptions and errors; pages 98-101
*
* Using throw, try-catch blocks; Listing 4-8 and 4-9
*
*/

#include <cstdio>

// This is the collection of standard exception classes also expressed as "std::exception"
// This group can be partitioned into logic errors, runtime errors, and language support errors
#include <stdexcept>

// Listing 4-8
// This struct throws an exception when forget() method is called with 0xFACE
struct Groucho {
  void forget(int x){
    if (x == 0xFACE){
      // std:runtime_error is initialized and thrown to the catch block at line 43
      // thrown exception stops normal program execution
      throw std::runtime_error{ "I'd be glad to make an exception." };
    }
    printf("Forgot 0x%x\n", x);
  }
};


int main() {

  // Initialize object of type Groucho
  Groucho groucho;

  // Run try-catch block to establish exception handlers. This is very similar to
  // try-except blocks in Python
  try {
    groucho.forget(0xC0DE);
    groucho.forget(0xFACE);
    groucho.forget(0xC0FFEE);   // This line does not run
  } catch (const std::runtime_error& e) {
    printf("Exception caught with message: %s\n", e.what());  // 'e' is the error message from line 25.
  }

  return 0;
}

/*
OUTPUT:

Forgot 0xc0de
exception caught with message: I'd be glad to make an exception.
*/
