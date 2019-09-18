/*
* Ch2 Example
*
* arrays.cpp
*
* Demonstrating array initialization and access; pages 42 - 43
*/

#include <cstdio>

  int main(){
  // Initialize arrays by declaring their size
  int array[100];

  // Or dynamically by using brackets
  // Remember array indexing starts at 0
  int my_array[] = {1, 2, 3, 4};

  printf("The third element is %d.\n", my_array[2]);

  // Can change array elements at any time like so:
  my_array[2] = 100;
  printf("The third element is %d.\n", my_array[2]);


  return 0;
}
