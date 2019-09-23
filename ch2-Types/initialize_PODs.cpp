/*
* Ch2 Example
*
* initialize_PODs.cpp
*
* Show syntax for initializing PODs and arrays; pages 60 - 61
*
*/

#include <cstdio>
#include <cstdint>


struct PodStruct {
  uint64_t a;
  char b[256];
  bool c;
};


int main(){

  // Initialize PodStruct objects with all fields zeroed
  // This does not compile:  PodStruct initialized_pod = 0;
  PodStruct initialized_pod1{};
  PodStruct initialized_pod2 = {};

  // Initialize PodStruct objects with set fields.  Braces are required.
  // This does not compile:  PodStruct initialized_pod(42, "Hello", true);
  // Can only omit fields from right to left
  // This does not compile:  PodStruct initialized_pod{42, true};
  PodStruct initialized_pod3{42, "Hello"};            // a & b set; not c
  PodStruct initialized_pod4 = {42, "Hello", true};   // all fields set

  // Arrays require brackets in addition to braces
  int array_1[]{1, 2, 3};
  int array_2[5]{};             // Array of length 5 {0, 0, 0, 0, 0}
  int array_3[5]{1, 2, 3};
  int array_4[5];              // Array of length 5; uninitialized values

  return 0;
}
