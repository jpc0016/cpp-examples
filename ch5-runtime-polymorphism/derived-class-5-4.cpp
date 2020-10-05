/*
* CH5 Example
*
* derived-class-5-4.cpp
*
* Demonstrate class inheritance; page 139
*
*
* Listing 5-4
*
*/
#include <cstdio>

struct BaseClass {};
struct DerivedClass : BaseClass {};

// The parameter is a reference to a BaseClass
void are_belong_to_us(BaseClass& base) {}

int main() {
  DerivedClass derived;
  are_belong_to_us(derived);
}
