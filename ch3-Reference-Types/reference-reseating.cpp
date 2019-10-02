/*
* Ch3 Example
*
* reference-reseating.cpp
*
* Show that references cannot be reseated; pages 80
* Demonstrate type references
*
* Listing 3-11
* Initialize an int reference then try to reseat it with a new value
*
*/

// '*' = pointer initialization operator when used with initialized type or dereference operator depending on which side of equals sign
// '&' = address-of operator

#include <cstdio>

int main() {

  int original = 100;

  // Initialize an int reference to the integer
  // From this point on, original_ref will ALWAYS refer to original
  int& original_ref = original;

  // Check their values;  both equal 100
  printf("Original: %d\n", original);
  printf("Reference: %d\n", original_ref);

  int new_value = 200;

  // Attempt to "reseat" original_ref to the new integer
  // Reseating does not work because original_ref does not point to 'new_value' after this assignment operation.
  // It still points to 'original'.  This line only assigns 'original' to the value of 'new_value' (200)
  original_ref = new_value;

  // Check values again; All values equal 200
  printf("\nOriginal: %d\n", original);
  printf("New Value: %d\n", new_value);
  printf("Reference %d\n", original_ref);

  return 0;
}
