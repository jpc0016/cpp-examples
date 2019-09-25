/*
* Ch2 Example
*
* featured_classes.cpp
*
* Demonstrate initializing fully featured classes; pages 62 - 64
* Also demonstrate narrowing conversions
*/

#include <cstdio>

struct Taxonomist {
  Taxonomist() {
    printf("(no argument)\n");
  }
  Taxonomist(char x) {
    printf("char: %c\n", x);
  }
  Taxonomist(int x) {
    printf("int: %d\n", x);
  }
  Taxonomist(float x) {
    printf("float: %f\n", x);
  }
};

int main(){

  Taxonomist t1;
  Taxonomist t2{ 'c' };
  Taxonomist t3{ 65537 };
  Taxonomist t4{ 6.02e23f };
  Taxonomist t5('g');
  Taxonomist t6 = { 'l' };
  Taxonomist t7{};
  Taxonomist t8();    // This constructor produces no output at all. This is interpreted as a blank function.

  // OUTPUTS:
  // (no argument)
  // char: c
  // int: 65537
  // float: 602000017271895229464576.000000
  // char: g
  // char: l
  // (no argument)

  // NARROWING CONVERSIONS
  float a{ 1 };
  float b{ 2 };

  // This silently narrows a/b (0.5) to 0 due to parentheses initialization
  int narrowed_result(a/b);

  // This will produce an error message due to braced initialization
  // int result{ a/b };

  //printf("narrowed_result: %d\n", narrowed_result);
  //printf("result: %d\n", result);

  return 0;
}
