/*
* Ch2 Example
*
* switch_statement.cpp
*
* Demonstrating switch statement on user defined types; pages 50 - 51
*
*  switch ( condition ) {
*  case (case-A): {
*      HANDLE CASE A
*    } break;
*  case (case-B): {
*      HANDLE CASE B
*    } break;
*  default: {
*      HANDLE DEFAULT CASE
*    }
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

  // Access Dinan element of class Race using '::' operator
  Race race = Race::Julian;

  // Input race to switch statement to evaluate which name is assigned to it.
  switch(race) {
    case Race::Dinan: {
      printf("You work hard!\n");
    } break;
    case Race::Teklan: {
      printf("You are very strong!\n");
    } break;
    case Race::Ivyn: {
      printf("You are a great leader!\n");
    } break;
    case Race::Moiran: {
      printf("My, how versatile you are!\n");
    } break;
    case Race::Camite: {
      printf("You're incredibly helpful!\n");
    } break;
    case Race::Julian: {
      printf("Anything you want!\n");
    } break;
    case Race::Aidan: {
      printf("What an enigma!\n");
    } break;
    // Note default condition does not require a break statement
    default: {
      printf("Error: unknown race!\n");
    }
  }

  return 0;
}
