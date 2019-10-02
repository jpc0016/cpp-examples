/*
* Ch3 Example
*
* constants.cpp
*
* Use cases of const; pages 82 - 83
* Listings 3-14 - 3-17
*
*/

// '&' = address-of operator
// '*' = pointer initialization operator or dereference operator

#include <cstdio>


void petruchio(const char* shrew){
  printf("Fear not, sweet wench, they shall not touch thee, %s\n", shrew);
  //shrew[0] = "K";   // This makes a compiler error: read-only variable is not assignable
}


int main() {

  petruchio("shrew");

  return 0;
}
