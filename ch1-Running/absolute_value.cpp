/*
* Ch1 Exercise 1-1, 1-2, and 1-3
*
* absolute_value.cpp
*
* Create a function called absolute_value() that returns the absolute absolute_value
* of a single argument. Change values to test each case; page 28
*/
#include <cstdio>

int absolute_value(int x){

  if (x > 0) return x;
  else if (x < 0) return (x * -1);

  // return 0 if neither of the above statements is true.
  return x;
}

int main(){

  int my_num = 20;
  int result = absolute_value(my_num);

  printf("The abolute value of %d is %d.\n", my_num, result);
  return 0;
}
