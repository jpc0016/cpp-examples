/*
* CH4 Example
*
* values-and-moves.cpp
*
* lvalues and rvalues; pages 124-126
* Making multiple functions of the same name with different parameters is called
* function overloading
*
* Listing 4-33, 4-34
*
*/

#include <cstdio>
#include <utility>    // utility is required to use std::move()

// This function takes an lvalue x
void ref_type(int &x){
  printf("lvalue reference %d\n", x);
}


// This function takes an rvalue x
void ref_type(int &&x){
  printf("rvalue reference %d\n", x);
}


int main() {
  auto x = 1;
  //ref_type(x);    // Uses lvalue function since it has a name (x)

  // Listing 4-34 addition
  // std:move() can cast an lvalue reference into an rvalue reference
  ref_type(std::move(x));   // std::move() changes the lvalue x into an rvalue.

  ref_type(2);    // Uses rvalue function since it has a value (2) without a name
  ref_type(x + 2);  // Uses rvalue function since adding 2 to x is not bound to a name

  /*
  OUTPUT:

  rvalue reference 1
  rvalue reference 2
  rvalue reference 3
  */

  return 0;
}
