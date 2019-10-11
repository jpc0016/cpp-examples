/*
* Ch3 Exercise 3-3
*
* exercise3-double-list.cpp
*
* Demonstrate forward-linked lists; pages 78 - 79, 86
* Add Element * previous to make a double-linked-list
* Add an insert_before method to Element. Traverse list from front to back, then back to front.
* Print operating_number inside each loop
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
  Element* previous{};

  // Insert new_element after the current element
  void insert_after(Element* new_element) {

    // current 'next' (or 'next' of 'this') is set to member 'next' of new_element
    // In a new linked-list, current 'next' is nullptr
    //new_element -> next = next;
    new_element -> previous = this;

    // 'next' of 'this' is set to the new element
    // This "inserts" new_element between current 'next' and nullptr
    next = new_element;
  }

  // Insert next_element before the current element
  void insert_before(Element* next_element){      // Initialize pointer to next element as nullptr; equivalent to Element* next = 0;


    // trooper1 address is set to trooper2 previous.  So trooper2 points back to trooper1

    // 'previous' element of trooper1 is set to the current element's 'previous' member
    next_element -> previous = previous;
    previous = next_element;
    next_element->next = this;
    next_element->previous->next = next_element;

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
  //trooper2.insert_before(&trooper1);

  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;
  //trooper3.insert_before(&trooper2);


  printf("trooper1 next: %x\n", trooper1.next);
  printf("trooper1 address: %x\n", &trooper1);
  printf("trooper1 previous: %x\n\n", trooper1.previous);        // trooper1's previous{} value is null

  printf("trooper2 next: %x\n", trooper2.next);
  printf("trooper2 address: %x\n", &trooper2);
  printf("trooper2 previous: %x\n\n", trooper2.previous);

  printf("trooper3 next: %x\n", trooper3.next);
  printf("trooper3 address: %x\n", &trooper3);
  printf("trooper3 previous: %x\n\n", trooper3.previous);
  // Done inserting troopers so no insert_after() needed


  // Iterate over each element in the linked list
  // First initialize a pointer (cursor) to the address of first element (trooper1)
  // Middle statement (cursor;) checks if it is nullptr
  // Finally set cursor to the next element
  for (Element *cursor = &trooper1; cursor; cursor = cursor->next){
    printf("Stormtrooper: %c%c-%d\n   Next address: %x\n",
        // For each element, access their members in the print statment
        cursor->prefix[0],
        cursor->prefix[1],
        cursor->operating_number,
        cursor->next);
    printf("trooper2 previous: %x\n\n", trooper2.previous);
  }

  printf("\n");

  // Traverse list backwards
  // Currently misses the last stormtrooper; 'previous' of trooper2 is not being set to address of trooper1
  for (Element *new_cursor = &trooper3; new_cursor; new_cursor = new_cursor->previous){
    printf("Stormtrooper: %c%c-%d\n   Previous address: %x\n",
        new_cursor->prefix[0],
        new_cursor->prefix[1],
        new_cursor->operating_number,
        new_cursor->previous);


  }

  return 0;
}
