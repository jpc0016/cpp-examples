/*
* CH4 Example
*
* static-duration.cpp
*
* Cover static storage duration; pages 90-92
*
* Rat-thing example
*
* POD = Plain Old Data class
*
* Use 'static' or 'extern' keywords to declare
* static variables at the same level of declared functions - global scope or
* namespace scope
*
* local static variables are declared at function scope.  They begin on first
* invocation but end when program exits
*/

#include <cstdio>

// globally declared static variable is accessible throughout program
static int rat_things_power = 200;

/* 'static' specifies internal linkage, meaning the variable is inaccessible to other
translation units.

'extern' keyword can be used to specify external linkage
*/


void power_up_rat_thing(int nuclear_isotopes){
  // move rat_things_power here to make it a local static variable (page 92); however,
  // the print statements in main() need to be moved inside this function because
  // rat_things_power can no longer be globally accessed.
  // static int rat_things_power = 200;

  rat_things_power = rat_things_power + nuclear_isotopes;

  // Value of waste_heat is not saved between function calls.  Its storage duration begins
  // when power_up_rat_thing is called and when the function returns.
  const auto waste_heat = rat_things_power * 20;

  if(waste_heat > 10000){
    printf("Warning! Hot doggie!\n");
  }
}



int main(){

  printf("Rat-thing power: %d\n", rat_things_power);
  // 200

  power_up_rat_thing(100);
  printf("Rat-thing power: %d\n", rat_things_power);
  // 300

  power_up_rat_thing(500);
  printf("Rat-thing power: %d\n", rat_things_power);
  // Warning! Hot doggie!
  // 800
}
