/*
* Ch2 Example
*
* methods_controls_constructors.cpp
*
* Demonstrating methods, access controls, and constructors; pages 55 - 59
* Member functions of classes
*/

#include <cstdio>

// Keeps track of the current year
// struct and class are the same except for access controls.  Class declares
// members private by default
struct ClockOfTheLongNow {

  // Add constructor inside the class/struct definition (page 58)
  ClockOfTheLongNow(){
    year = 2019;
  }

  // Add another constructor that takes int year_in as input
  // if set_year() returns FALSE, set to TRUE using '!' to set default year
  ClockOfTheLongNow(int year_in){
    if (!set_year(year_in)){
      year = 2019;
    }
  }

  void add_year(){
    year++;
  }
  // Add below methods
  // This method uses input validation to ensure year is never
  // less than 2019.  'year' becomes a private member to ensure users cannot
  // access it directly.
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
  ClockOfTheLongNow clock{2020};    // clock() can now take an input due to constructor
  printf("Default year: %d\n", clock.get_year());

  // Initialize year, add year, then print result
  // clock.year = 2017;         <-- this fails. year is private
  if (!clock.set_year(2018)){  // will fail; 2018 < 2019
    clock.set_year(2019);
  }

  clock.add_year();
  //printf("Year: %d\n", clock.year);         <-- this fails. year is private
  printf("Year: %d\n", clock.get_year());

  // repeat above steps
  // clock.add_year();
  // printf("Year: %d\n", clock.year);





  return 0;
}
