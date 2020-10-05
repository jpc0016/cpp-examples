/*
* CH5 Example
*
* virtual-members-5-7.cpp
*
* Override inherited methods with a derived class' own
* implementation; pages 140-141
*
*
* Listing 5-7
*
*/
#include <cstdio>

struct BaseClass {
  virtual const char* final_message() const {
    return "We apologize for the incontinence.";
  }
};

struct DerivedClass : BaseClass {
  // override the inherited final_message() method with
  // 'override' keyword
  const char* final_message() const override {
    return "We apologize for the inconvenience.";
  }
};

int main() {
  BaseClass base;
  DerivedClass derived;
  BaseClass& ref = derived;

  printf("BaseClass:   %s\n", base.final_message());
  printf("DerivedClass:   %s\n", derived.final_message());
  printf("BaseClass&:   %s\n", ref.final_message());
}

/*
  Answer:

  BaseClass:   We apologize for the incontinence.
  DerivedClass:   We apologize for the inconvenience.
  BaseClass&:   We apologize for the inconvenience.

*/
