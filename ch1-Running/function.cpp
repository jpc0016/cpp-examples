/*
* Ch1 Example
*
* function.cpp
*
* Function demonstration; page 18
*/
#include <cstdio>

// Define step-function
int step_function(int x){
   // declare result variable
   int result = 0;

   if (x < 0){
     result = -1;
   } else if (x > 0){
     result = 1;
   }
   // if x = 0, no change will happen and it will simply return result.
   return result;

}


int main(){

  int num1 = 42;
  int result1 = step_function(num1); // result1 is 1

  int num2 = 0;
  int result2 = step_function(num2);  // result2 is 0

  int num3 = -346521;
  int result3 = step_function(num3);  // result3 is -1

  // Expand to three print statements
  printf("Num: %d, Step: %d\n", num1, result1);
  printf("Num: %d, Step: %d\n", num2, result2);
  printf("Num: %d, Step: %d\n", num3, result3);

  return 0;
}
