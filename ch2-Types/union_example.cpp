/*
* Ch2 Example
*
* union_example.cpp
*
* Demonstrating unions; pages 53 - 54
*
* Similar to PODs except they handle memory differently. Unions take up only as
* much memory as its largest member.  Have to track which union members are set
* or else "dumpster fires" occur.
*
* Unions begin with keyword 'union' followed by desired name
* Next list member types and their names
*
* Use dot operator (.) to specify union interpretation. This is similar to
* accessing members of a class but it's not the same.
*/

#include <cstdio>

union Variant {
  char string[10];
  int integer;
  double floating_point;
};

int main(){

  Variant v;

  v.integer = 42;
  printf("The ultimate answer: %d\n", v.integer);

  v.floating_point = 2.7182818284;
  printf("Euler's number e: %f\n", v.floating_point);

  // prints -1961734133 unless v.integer is set again.
  // Cannot reinterpret v as an integer
  // v.integer = 55;
  printf("A dumpster fire: %d\n", v.integer);


  return 0;
}
