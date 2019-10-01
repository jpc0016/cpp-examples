/*
* Ch3 Example
*
* references.cpp
*
* Demonstrate the safety of references; pages 77
*
* ClockOfTheLongNow reused from member-of-pointer.cpp
*/

  // '&' = address-of operator
  // '*' = dereference operator or pointer declaration when used with pointed-to type (Ex: int* new_pointer;)

#include <cstdio>


struct ClockOfTheLongNow {


  ClockOfTheLongNow(){
    year = 2019;
  }


  ClockOfTheLongNow(int year_in){
    if (!set_year(year_in)){
      year = 2019;
    }
  }


  bool set_year(int new_year){
    if (new_year < 2019) return false;
    year = new_year;
    return true;
  }

  int get_year(){
    return year;
  }

private:
  int year;
};


// Modify add_year() and move it outside struct ClockOfTheLongNow
// Clock argument is referenced with '&'
void add_year(ClockOfTheLongNow& clock){
  clock.set_year(clock.get_year() + 1);   // No deref operator needed
}


int main(){

  // Declare object clock
  ClockOfTheLongNow clock;

  // Print initial year
  printf("The year is %d.\n", clock.get_year());

  // clock is implicitly passed by reference
  // No need to pass a pointer to clock's address
  add_year(clock);

  // Print result of add_year()
  printf("The year is %d.\n", clock.get_year());


  return 0;
}
