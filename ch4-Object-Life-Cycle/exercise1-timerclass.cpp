/*
* Ch4 Exercise 4-1, 4-2
*
* exercise1-timerclass.cpp
* page 131
*
* Create a struct TimerClass. In its constructor, record current time of day in a field
* called 'timestamp' (compare with POSIX function gettimeofday)
*
*/

// '*' = pointer initialization operator when used with initialized type or dereference operator depending on which side of equals sign
// '&' = address-of operator
// copy assignment operator: operator=

#include <cstdio>
#include <cstring>
#include <string>
#include <sys/time.h>


struct TimerClass {

  // 4-1
  // Constructor to record current time
  TimerClass(timeval current_time)
    : timestamp{ current_time.tv_usec } {
      printf("timestamp at construction: %ld\n", timestamp);
    }

  // 4-3
  // Copy constructor to handle timeval structure from gettimeofday()
  // TimerClass(timeval& timer)
  //   : timestamp{ timer.tv_usec } {     // need to extract time attributes from timer into timestamp
  //     printf("timestamp at construction: %ld\n", timestamp);
  //
  //     // long x = 0;
  //     // while (x < 100) {
  //     //   timestamp++;
  //     //   x++;
  //     //}
  //
  //   }

  // 4-2
  // Destructor records current time and prints time difference from construction
  // to object destruction
  ~TimerClass(){
    gettimeofday(&new_time, nullptr);
    printf("Timestamp at destruction: %ld\n", new_time.tv_usec);
    printf("Time difference: %ld\n", (new_time.tv_usec - timestamp));
  }

private:
  long timestamp;
  struct timeval new_time;
};


int main() {

  struct timeval time;
  gettimeofday(&time, nullptr);
  // note: string types require 'std::' in front or 'using namespace std;'
  //int time = 1000;
  TimerClass a{ time };

  long x = 0;
  while (x < 100000000) {
    x++;
  }

  return 0;
}
