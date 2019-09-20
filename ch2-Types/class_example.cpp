/*
* Ch2 Example
*
* class_example.cpp
*
* Demonstrating classes; pages 52 - 53
*
* Simplest type of classes are plain-old-data classes (PODs)
*
* PODs begin with keyword 'struct' followed by desired name
* Next list member types and their names
*
* As a general rule, order members from largest to smallest in POD definitions
*/

#include <cstdio>

struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};


int main(){

  // Declare a variable of type 'Book'
  Book neuromancer;

  // Access members of the variable using dot operator (.)
  neuromancer.pages = 271;

  printf("Neuromancer has %d pages.\n", neuromancer.pages);

  return 0;
}
