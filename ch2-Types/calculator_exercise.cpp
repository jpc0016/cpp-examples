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
    function = f;
  }

  // Exercise 2-3: Create a method called int calculate with two integer inputs
  // It performs operation based on value of constructor argument (f or function)
  int calculate(int a, int b){
    int result;

    if (function == Operation::Add) result = a + b;
    else if (function == Operation::Subtract) result = a - b;
    else if (function == Operation::Multiply) result = a * b;
    else if (function == Operation::Divide) result = a/b;

    // Don't forget to return a result because the function is type 'int' or this warning happens:
    // warning: control reaches end of non-void function [-Wreturn-type]
    return result;
  }

  // Optional destructor with print statement.
  ~Calculator(){
    printf("When is this called?\n");
  }

private:
  Operation function;

};


int main(){

  Operation f = Operation::Multiply;

  Calculator C{f};

  int mult;
  mult = C.calculate(1, 2);
  printf("Multiplication result: %d\n", mult);
  C.~Calculator();

  // Exercise 2-4: Experiment with different means of initializing Calculator instances.
  Operation d = Operation::Divide;

  Calculator Calc={d};

  int div;
  div = Calc.calculate(55, 5);
  printf("Division result: %d\n", div);

  return 0;
}
