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
#include <cstring>
#include <new>

// Read array elements from upper or lower arrays
void read_from(char* arg_array){
  // Initialize "holding array"
  // strlen assumes there's a null termination. Should check for null termination prior to using arrays
  size_t size = strlen(arg_array);
  char * holding_array = new char[size]{'a'};

  // printf("Size of holding_array: %lu\n", sizeof(holding_array));
  // printf("Strlen of holding_array: %zu\n\n", strlen(holding_array));


  // printf("holding: %s\n", holding_array);
  // printf("input array: %s\n", arg_array);

  //size_t requires std:: notation or <cstddef> library
  for(std::size_t i = 0; i<size; i++){
    holding_array[i] = arg_array[i];
  }
  printf("holding after loop: %s\n", holding_array);
}


// Write values to upper or lower arrays. Ensure writing remains in bounds of array by determining size
// of input array.  Arguments: array name, size
void write_to(char* arg_array, size_t size){
  // Initialize string for use in scanf
  char* str;

  bool exit = false;

  // Use while loop to ensure intput validation when writing to target array.
  while (!exit){
    printf("\nEnter characters to the array.  No larger than %zu elements.\n", size);
    scanf("%s", str);
    printf("\nYou entered: %s\n", str);

    // Check length of str before assigning its characters to the char array
    size_t length = strlen(str);
    printf("Size of str is: %zu\n", length);
    if (length > size) {
      printf("The string you entered is too long.\n");
      continue;
    }
    else {
      for (std::size_t j = 0; j<=length; j++){
        // no pointer or dereference operator required since string is already a char pointer
        arg_array[j] = str[j];
        exit = true;
      }
    }

    printf("\nOutput array: %s\n", arg_array);
  }

}


int main() {

  // Initialize char arrays
  char lower[] = "abc?e";
  char upper[] = "ABC?E";

  char new_array[]{0};
  //printf("lower: %s\n", lower);
  read_from(lower);
  write_to(new_array, 5);

  // This points to the first member of upper[] array
  char* upper_ptr = upper;  // Equivalent: &upper[0]

  // Replace question marks in both arrays
  lower[3] = 'd';           // lower now contains a b c d e \0
  upper_ptr[3] = 'D';       // upper now contains A B C D E \0

  char letter_d = lower[3];     // letter_d = 'd'
  char letter_D = upper_ptr[3]; // letter_D = 'D'

  //printf("lower: %s\nupper: %s\n", lower, upper);

  // This is out-of-bounds memory writing. Will return a warning
  lower[7] = 'g';


  return 0;
}
