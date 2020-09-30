/*
* CH5 Example
*
* consolelogger.cpp
*
* ConsoleLogger class to demonstrate polymorphism; pages 134 - 136
*
*
* Listings 5-1 and 5-2
*
*/
#include <cstdio>
#include <stdexcept>

// Add new logger from Listing 5-2
struct FileLogger {
  void log_transfer(long from, long to, double amount){
      printf("[file] %ld,%ld,%f\n", from, to, amount);
  }
};


struct ConsoleLogger {
  void log_transfer(long from, long to, double amount){
    printf("%ld -> %ld: %f\n", from, to, amount);
  }
};

// Add enum to switch between different loggers (Listing 5-2)
enum class LoggerType {
  Console,
  File
};

struct Bank {
  // Default initialization of logger type
  Bank() : type { LoggerType::Console } { }

  // sets logger type to variable 'type'. Default logger type is
  // 'Console'
  void set_logger(LoggerType new_type) {
    type = new_type;
  }

  void make_transfer(long from, long to, double amount){

    switch(type) {
      case LoggerType::Console: {
        consoleLogger.log_transfer(from, to, amount);
        break;
      } case LoggerType::File: {
        fileLogger.log_transfer(from, to, amount);
        break;
      } default: {
        throw std::logic_error("Unknown Logger type encountered.");
      } }
    }
  private:
    LoggerType type;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
    /* log_transfer already defined in ConsoleLogger so no 'long' or 'double'
    Remove these two commands in Listing 5-2
    logger.log_transfer(from, to, amount);
  }
  ConsoleLogger logger; */
};

int main() {
  // Listing 5-1
  Bank bank;
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);

  // Add in Listing 5-2
  bank.set_logger(LoggerType::File);
  bank.make_transfer(3000, 2000, 75.00);

  /*
  OUTPUT:

1000 -> 2000: 49.950000
2000 -> 4000: 20.000000
[file] 3000,2000,75.000000

  */
}
