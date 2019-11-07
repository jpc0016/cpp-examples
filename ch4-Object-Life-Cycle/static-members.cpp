/*
* CH4 Example
*
* static-members.cpp
*
* local static variables; pages 92-94
*
* Rat-thing example
*
* static members are members of a class that are not associated with a particular
* instance of a class. Must be referred to by scope resolution operator ::
*/

#include <cstdio>

// Modifying a static member changes all classes with that member modification
// Change power_up_rat_thing and rat_things_power to static members of a RatThing class
struct RatThing {
  static int rat_things_power;

  // This is a static method of the class RatThing
  static void power_up_rat_thing(int nuclear_isotopes){

    // no scope resolution operator needed because rat_things_power is within scope
    rat_things_power = rat_things_power + nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;

    if (waste_heat > 10000) {
      printf("Warning! Hot Doggie!\n");
    }
    printf("Rat-thing power: %d\n", rat_things_power);
  }

};

// scope resoultion required because you are accessing rat_things_power from
// outside the class scope
int RatThing::rat_things_power = 200;

int main(){

  // Invoke power_up_rat_thing() in RatThing class
  RatThing::power_up_rat_thing(100);
  RatThing::power_up_rat_thing(500);

}
