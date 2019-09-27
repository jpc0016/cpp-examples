/*
* Ch3 Example
*
* member-of-pointer.cpp
*
* Demonstrate member-of-pointers; pages 71 - 72
*
* These are also called arrow pointers/operators (->)
* ClockOfTheLongNow reused from methods_controls_constructors.cpp
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

  void add_year(){
    year++;
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



int main(){

  // Declare object clock
  ClockOfTheLongNow clock;

  // Arrow pointer performs two tasks:
  // 1. dereferences a pointer
  // 2. accesses a member of the pointed-to object

  // Store clock's address into clock_ptr using '&'
  // Use arrow operator to set the year member of clock to 2020
  // Arrow operator is performed on a pointer (clock_ptr) to access its member method (set_year())
  ClockOfTheLongNow* clock_ptr = &clock;
  clock_ptr -> set_year(2020);


  printf("Address of clock: %p\n", clock_ptr);
  printf("Value of clock's year: %d\n", clock_ptr->get_year());
  // Below produces the same result:
  // printf("Value of clock's year: %d\n", (*clock_ptr).get_year());

  return 0;
}
