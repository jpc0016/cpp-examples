/*
* Ch3 Example
*
* buffer-overflow-pointers.cpp
*
* Show the dangers of pointers with pointer arithmetic; pages 74 - 76
* Listing 3-7
*/

// '&' = address-of operator
// '*' = pointer declaration character or pointer dereference operator; depending on which
// side of the equals sign

#include <cstdio>

int main() {

  // Initialize char arrays
  char lower[] = "abc?e";
  char upper[] = "ABC?E";

  // Pointer initialization
  // This points to the first member of upper[] array
  char* upper_ptr = &upper[0];  // "Address of upper[] at position 0"

  // Replace question marks in both arrays
  // This is read as: "pointer to first entry of lower[] then offset 3"
  *(lower + 3) = 'd';           // lower now contains a b c d e \0
  *(upper_ptr + 3) = 'D';       // upper now contains A B C D E \0

  char letter_d = *(lower + 4);     // letter_d = 'd'
  char letter_D = *(upper_ptr + 4); // letter_D = 'D'

  printf("lower: %s\nupper: %s\n", lower, upper);

  // Writing to an area in memory that is not assigned to lower[]
  *(lower + 7) = 'g';


  return 0;
}
