/*
* Ch3 Example
*
* auto-type.cpp
*
* Using 'auto' type; pages 84 and 86
* Listing 3-19
*
*/

// '&' = address-of operator
// '*' = pointer initialization operator or pointer dereference operator depending on which side of equals sign

#include <cstdio>

// auto helps make code more resilient to refactoring
struct Dwarf {
  float height;
  bool stocky = true;
};

Dwarf dwarves[13];    // Create 13 Dwarf objects

struct Contract {
  int company { 0 };
  void add(const Dwarf&){
      company += 1;
  }
};


void form_company(Contract &contract) {
  // If the type of 'dwarves' changes, this for loop does not require tweaking
  // This tweaking is called 'refactoring'
  for (const auto& dwarf : dwarves) {
    contract.add(dwarf);
  }
}


int main() {

  // This type declaration is what we're used to seeing.
  int answer = 42;

  //'auto' can automatically detect the type because 42 is an integer
  // The following are valid declarations using braced initialization
  // Can also initialize with parentheses and equals sign
  auto the_answer { 42 };             // int
  auto foot { 12L };                  // long
  auto rootbeer { 5.0F };             // float
  auto cheeseburger { 10.0 };         // double
  auto politifact_claims { false };   // bool
  auto cheese { "string" };           // char[7] (don't forget null terminator!)

  // Can add '*', '&', and 'const' modifiers to auto types as well
  // Resulting type is guaranteed by auto
  auto year { 2019 };                 // int
  auto& year_ref = year;              // int&
  const auto& year_cref = year;       // const int&
  auto* year_ptr = &year;             // int*
  const auto* year_cptr = &year;      // const int*





  return 0;
}
