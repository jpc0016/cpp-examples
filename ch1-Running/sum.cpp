/*
* Ch1 Exercise 1-1, 1-2, and 1-3
*
* sum.cpp
*
* Create a function called absolute_value() that returns the absolute absolute_value
* of a single argument; page 28
*/
#include <cstdio>

int sum(int x, int y){
  return x + y;
}

int main(){

  int num1 = 20;
  int num2 = 10;

  int result = sum(num1, num2);

  printf("%d + %d = %d.\n", num1, num2, result);
  return 0;
}
