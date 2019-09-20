/*
* Ch2 Example
*
* enumeration.cpp
*
* Demonstrating enumerations; pages 49 - 50
*
* Three user defined types:
* Enumerations
* Classes
* Unions
*/

#include <cstdio>

enum class Race {
  Dinan,
  Teklan,
  Ivyn,
  Moiran,
  Camite,
  Julian,
  Aidan
};


int main(){

  // Format for accessing an enumerated class item
  Race langobard_race = Race::Aidan;


  return 0;
}
