/*
* Ch2 Example
*
* initialize_types.cpp
*
* Demonstrating object initialization; pages 59 - 60
* Initialize types of numbers using braced initialization
*/

#include <cstdio>

int main(){

  // Initialize an object of fundamental type to zero
  int a = 0;      // Initialized to 0
  int b{};        // Initialized to 0
  int c = {};    // Initialized to 0
  int d;         // Initialized to 0 but unreliable

  // Initialize to an arbitrary value
  int e = 42;      // Initialized to 42
  int f{ 42 };     // Initialized to 42
  int g = { 42 };  // Initialized to 42
  int h(42);       // Initialized to 42


  return 0;
}
