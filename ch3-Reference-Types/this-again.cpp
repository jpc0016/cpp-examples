/*
* Ch3 Example
*
* this-again.cpp
*
* Use 'this' in structure; pages 81 - 84
* marking methods as const
* Using member initializer lists
* Listing 3-13, 3-15 - 3-18
*
* ClockOfTheLongNow reused from member-of-pointer.cpp and references.cpp
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


  bool set_year(int year){
    if (year < 2019) return false;
    // Changed year to specify current object with 'this' because too many 'year' variables is confusing.
    this->year = year;
    return true;
  }


// Marking a method as constant means it will not modify the current object's state
// This is a read-only method and prevents year from being modified.  Attempting to modify it
// results in a compiler error
  int get_year() const {
    return year;
  }


  // Add is_leap_year() constant method
  // This function relies on get_year() being a constant method because clock is being passed
  // as a constant reference
  bool is_leap_year(const ClockOfTheLongNow& clock){
    if (clock.get_year() % 4 > 0) return false;
    if (clock.get_year() % 100 > 0) return true;
    if (clock.get_year() % 400 > 0) return false;
    return true;
  }


private:
  int year;
};


// Listing 3-17
// Initialize structure with constant member variable
// Value of 'name' cannot change
// struct Avout {
//   const char* name = "Erasmus";
//   ClockOfTheLongNow apert;
// };

// Listing 3-18
// Member initializer lists
// Place a ':' after the argument list in a constructor.  Braced initialization allows
// member variables 'name' and 'apert' to be initialized to whatever you input
struct Avout {

  // Had to change year_of_apert to type 'int' for program to compile
  // Might submit as errata
  Avout(const char* name, int year_of_apert)
  : name { name }, apert { year_of_apert } {
  }

  void announce() const {
    printf("My name is %s and my next apert is %d.\n", name, apert.get_year());
  }
  const char* name;
  ClockOfTheLongNow apert;
};





// If you pass the struct Avout as a constant, nothing can be changed within avout
// Does not compile for this reason alone.  Also add_year() is not a member of struct ClockOfTheLongNow
// void does_not_compile(const Avout& avout){
//   avout.apert.add_year();
// }


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

  // Listing 3-18 Method initializer list
  // This is braced initialization
  Avout raz{ "Erasmus", 3010};
  Avout jad{ "Jad", 4000};
  raz.announce();
  jad.announce();


  return 0;
}
