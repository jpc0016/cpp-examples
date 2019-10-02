/*
* Ch3 Example
*
* this-example.cpp
*
* Example of this pointer; pages 80 - 81
*
* Listing 3-12
* Sometimes the current object needs to be accessed when writing a method.
* 'This' is usually implicit when accessing members, but sometimes disambiguation is required.
* Same code as forward-linked-list.cpp
*
* Stormtrooper designations from forward-linked-list.cpp (Listing 3-9)
*/

#include <cstdio>


// Example of a 'singly-linked' list element (Listing 3-9)
struct Element {
  Element* next{};    // Initialize pointer to next element as nullptr; equivalent to Element* next = 0;

  void insert_after(Element* new_element) {

    // member 'next' of new_element is set to the current 'next' (or 'next' of 'this')
    // In a new linked-list, current 'next' is nullptr
    new_element -> next = this->next;

    // 'next' of 'this' is set to the new element
    // This "inserts" new_element between current 'next' and nullptr
    this->next = new_element;
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
  trooper1.insert_after(&trooper2);       // Inserting trooper2 as next element

  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;
  trooper2.insert_after(&trooper3);

  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;
  // Done inserting troopers so no insert_after() needed


  // Iterate over each element in the linked list
  // First initialize a pointer (cursor) to the address of first element (trooper1)
  // Middle statement (cursor;) checks if it is nullptr
  // Finally set cursor to the next element
  for (Element *cursor = &trooper1; cursor; cursor = cursor->next){
    printf("Stormtrooper: %c%c-%d\n",
        // For each element, access their members in the print statment
        cursor->prefix[0],
        cursor->prefix[1],
        cursor->operating_number);
  }

  return 0;
}
