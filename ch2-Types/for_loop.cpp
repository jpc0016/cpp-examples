/*
* Ch2 Example
*
* for_loop.cpp
*
* Demonstrating for loop; pages 43 - 44
*/

// import <cstddef> again
#include <cstdio>
#include <cstddef>

  int main(){

    /*
    Format:
    for(init-statement; conditional; iteration-statement){

    }
    */

    // smallest possible value of an unsigned number is zero
    unsigned long maximum = 0;

    // Going to iterate over an array
    unsigned long values[] = {10, 50, 20, 40, 0};

    // Continuously update maximum when a higher number is found.
    // See note on page 44 for size_t justification
    for(size_t i = 0; i < 5; i++){
      if(values[i] > maximum) maximum = values[i];
    }

    // print result
    printf("The maximum value of values[] is %lu\n", maximum);


    /* RANGE-BASED FOR LOOP

    Format:
    for(element-type element-name: array-name){

      }*/
    unsigned long new_max = 0;

    unsigned long new_values[] = {10, 20, 60, 100, 0};

    for(unsigned long value: new_values){
      if (value > new_max) new_max = value;
    }

    printf("\nThe second maximum value is %lu\n", new_max);

    return 0;
  }
