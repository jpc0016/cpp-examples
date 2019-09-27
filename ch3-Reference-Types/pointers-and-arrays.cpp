/*
* Ch3 Example
*
* pointers-and-arrays.cpp
*
* Show relationships between pointers and arrays; pages 72 - 74
*
* Best colleges!
*/

// '&' is the address-of operator
// '*' is the dereference operator or pointer declaration when used with pointed-to type

#include <cstdio>


struct College {
  char name[256];
};


// print_name example in listing 3-4
void old_print_name(College* college_ptr){
  // Print statement is also a pointer decay because %s expects a C-style string
  // which cuts off after the first element in best_colleges
  printf("%s College\n", college_ptr->name);
}


// print_names example in listing 3-5
// To handle decay, pass both the pointer to first array element and the array size
void print_names(College* colleges, size_t n_colleges){
  for (size_t i = 0; i < n_colleges; i++) {
    // Bracket notation [] also works with pointers
    printf("%s College\n", colleges[i].name);
  }
}


int main() {

  // First example on page 72
  int key_to_the_universe[]{3,6,9};
  int* key_ptr = key_to_the_universe;   // points to the first element of key_to_the_universe

  College best_colleges[] = {"Magdalen", "Nuffield", "Kellogg"};

  // Because old_print_name() takes a pointer as input, the best_colleges array decays to a
  // pointer to its first element.
  // old_print_name(best_colleges);
  print_names(best_colleges, sizeof(best_colleges)/sizeof(College));


  // POINTER ARITHMETIC
  // Direct approach of obtaining n-th element:
  College* third_college_ptr = &best_colleges[2];

  // Pointer arithmetic uses the pointed-to type to determine the correct byte offset
  // This is equivalent:
  College * third_college = best_colleges + 2;

  return 0;
}
