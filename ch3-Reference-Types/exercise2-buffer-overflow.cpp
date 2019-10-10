/*
* Ch3 Exercise 2
*
* exercise2-buffer-overflow.cpp
*
* Add a read_from and write_to function. These should read or write to upper or lower
* pages 74 - 76, 86
* Listing 3-6
*/

// '&' = address-of operator
// '*' = pointer declaration character or pointer dereference operator; depending on which
// side of the equals sign

#include <cstdio>

int main() {

  // Initialize char arrays
  char lower[] = "abc?e";
  char upper[] = "ABC?E";

  // This points to the first member of upper[] array
  char* upper_ptr = upper;  // Equivalent: &upper[0]

  // Replace question marks in both arrays
  lower[3] = 'd';           // lower now contains a b c d e \0
  upper_ptr[3] = 'D';       // upper now contains A B C D E \0

  char letter_d = lower[3];     // letter_d = 'd'
  char letter_D = upper_ptr[3]; // letter_D = 'D'

  printf("lower: %s\nupper: %s\n", lower, upper);

  // This is out-of-bounds memory writing.
  lower[7] = 'g';


  return 0;
}
