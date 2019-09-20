/*
* Ch2 Example
*
* method_example.cpp
*
* Demonstrating methods and access controls; pages 55 - 57
* Member functions of classes
*/

#include <cstdio>

// Keeps track of the current year
struct ClockOfTheLongNow {
  void add_year(){
    year++;
  }
  // Add below methods
  bool set_year(int new_year){
    if (new_year < 2019) return false;
    year = new_year;
    return true;
  }

  int get_year(){
    return year;
  }

private:
  int year; // year becomes private
};


int main(){

  // Declare object clock
  ClockOfTheLongNow clock;

  // Initialize year, add year, then print result
  clock.year = 2017;
  clock.add_year();
  printf("Year: %d\n", clock.year);

  // repeat above steps
  clock.add_year();
  printf("Year: %d\n", clock.year);





  return 0;
}
