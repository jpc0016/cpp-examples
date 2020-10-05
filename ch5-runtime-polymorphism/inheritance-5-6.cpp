/*
* CH5 Example
*
* inheritance-5-6.cpp
*
* Demonstrate member inheritance; pages 139-140
*
*
* Listing 5-6
*
*/
#include <cstdio>

struct BaseClass {
  int the_answer() const {
    return 42;
  }
  const char* member = "gold";
private:
  const char* holistic_detective = "Dirk Gently";
};

struct DerivedClass : BaseClass {};

int main() {
  DerivedClass x;
  printf("The answer is %d\n", x.the_answer());
  printf("%s member\n", x.member);

  // The below doesn't compile because holistic_detective is a private field
  // printf("%s's Holistic Detective Agency\n", x.holistic_detective);
}

/* Answer:

  The answer is 42
  gold member
*/
