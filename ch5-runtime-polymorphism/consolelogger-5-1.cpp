/*
* CH5 Example
*
* consolelogger-5-1.cpp
*
* ConsoleLogger class to demonstrate polymorphism; pages 134
*
*
* Listing 5-1
*
*/
#include <cstdio>


struct ConsoleLogger {
  void log_transfer(long from, long to, double amount){
    printf("%ld -> %ld: %f\n", from, to, amount);
  }
};


struct Bank {
  void make_transfer(long from, long to, double amount){
    // log_transfer already defined in ConsoleLogger so no 'long' or 'double'
    logger.log_transfer(from, to, amount);
  }
  ConsoleLogger logger;
};

int main() {

  Bank bank;
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);
}
