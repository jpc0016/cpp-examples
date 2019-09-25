/*
* Ch2 Exercise 2-1 - 2-4
*
* calculator_exercise.cpp
*
* Create a Calculator based on exercises 2-1 to 2-4
*/

#include <cstdio>

// Exercise 2-1: Create an enum class Operation that has values Add, Subtract,
// Multiply, and Divide.
enum class Operation {
  Add,
  Subtract,
  Multiply,
  Divide
};

// Exercise 2-2: Create a struct Calculator with a single constructor that takes
// an Operation
struct Calculator {
  Calculator(Operation f){
    Operation function = f;
  }

  // Exercise 2-3: Create a method in Calculator called int calculate() that
  // takes two integers
  int calculate(int a, int b){
    if (function = Operation::Add) return (a + b);
    if (function = Operation::Subtract) return (a - b);
    if (f == "Multiply") return (a * b);
    if (f == "Divide") return (a/b);
  }
};


int main(){

  Operation f = Operation::Add;

  Calculator C(f);

  return 0;
}
