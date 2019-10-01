/*
* Ch3 Example
*
* forward-linked-list.cpp
*
* Demonstrate forward-linked lists; pages 78 - 79
*
* Listing 3-9 and 3-10
* Each element holds a pointer to the next element.  Last element of the linked
* lists holds a nullptr.  Elements can be discontinuous in memory.
*
* Stormtrooper designations
*/

#include <cstdio>


// Example of a 'singly-linked' list element (Listing 3-9)
struct Element {
  Element* next{};    // Initialize pointer to next element as nullptr; equivalent to Element* next = 0;

  void insert_after(Element* new_element) {

    // member 'next' of new_element is set to the current 'next' (or 'next' of 'this')
    new_element -> next = next;

    // 'next' of 'this' is set to the new element
    next = new_element;
  }

// These attributes are specific to the stormtrooper example
char prefix[2];
short operating_number;
};

int main() {

  // Linked-list traversal (Listing 3-10)
  // Initialize trooper elements
  Element trooper1, trooper2, trooper3;
  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 421;
  trooper1.insert_after(&trooper2);       // trooper2 is next element

  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;
  trooper2.insert_after(&trooper3);

  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;


  return 0;
}
