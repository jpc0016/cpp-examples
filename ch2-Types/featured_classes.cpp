/*
* Ch2 Example
*
* featured_classes.cpp
*
* Demonstrate initializing fully featured classes; pages 62 - 63
*
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

  return 0;
}
