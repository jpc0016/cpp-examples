/*
* CH4 Example
*
* copy-assignment-simplestring.cpp
*
* Copy Assignment Operator; pages 119-121
* This is the other method of making a copy in C++. Can create a copy of an
* object and assign it to another existing object.
*
* syntax:   'operator='
*
* Listing 4-29, 4-30, 4-31
*
*/

#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {

  // constructor that initializes max_size
  SimpleString(size_t max_size)
    : max_size{ max_size },
     length{} {
       if (max_size == 0) {
         throw std::runtime_error{ "Max size must be at least 1." };
       }

       // Allocation of buffer is handled here. Since allocation and deallocation of buffer are handled
       // by constructor and destructor respectively, you'll never leak storage. Also called
       // Constructor Acquires, Destructor Releases (CADRe)
       buffer = new char[max_size];
       buffer[0] = 0;   // initialize first character of buffer as null byte
  }


  ~SimpleString(){
    delete[] buffer;  // Deallocates the memory pointed to by buffer
  }

/*
===============================================
begin Listing 4-15 additions
===============================================
*/

  // function to print the string
  void print(const char* tag) const { // this is a const method because it does not alter the state of SimpleString
    printf("%s: %s", tag, buffer);
  }

  // Adds line, x, to end of string and adds new line character; x is a null terminated string
  bool append_line(const char* x){

    // strlen function definition:    size_t strlen(const char* str);
    const auto x_len = strlen(x);
    if (x_len + length + 2 > max_size) return false;

    // strncpy function definition:   char* std::strncpy(char* destination, const char* source, std::size_t num);
    // destination address, source address, number of characters to copy
    std::strncpy(buffer + length, x, max_size - length);

    // Add length of string x to current length. Add newline and null byte to end of buffer
    // return true to indicate successful append_line operation
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

  /*
  ===============================================
  begin Listing 4-29 and 4-30 additions
  ===============================================

  copy-Constructor using copy assignment operator (operator=)
  */
  SimpleString& operator=(const SimpleString& other) {
    if (this == &other) return *this;

    const auto new_buffer = new char[other.max_size];     // allocate a new buffer of original object's size (other.max_size)
    delete[] buffer;            // Deallocates the memory pointed to by buffer
    buffer = new_buffer;        // copy newly allocated buffer (new_buffer) to current buffer
    length = other.length;      // copy length of other object to new length
    max_size = other.max_size;  // copy max_size of other object to new max_size
    // used strncpy instead because strcpy_s is microsoft specific
    strncpy(buffer, other.buffer, max_size);     // copy contents of other.buffer into current buffer

    return *this;
  }


private:
  size_t max_size;
  char* buffer;
  size_t length;
};

/*
===============================================
begin Listing 4-18 additions
===============================================
*/
struct SimpleStringOwner {

  // SimpleStringOwner inherits from string of type SimpleString
  SimpleStringOwner(const char* x)
    : string{ 10 } {
    if (!string.append_line(x)) {
      throw std::runtime_error{ "Not enough memory!" };
      }
    // Remember that print() uses the contents of buffer so its print statement looks like 'Constructed: x'.  'Constructed' is the tag in print() function definition.
    string.print("Constructed");
    }

    // This destructor is called before SimpleString's destructor hence the print statement: 'About to destroy: x'
  ~SimpleStringOwner() {
    string.print("About to destroy");
  }
private:
  SimpleString string;
};


int main() {

  /*
  ===============================================
  begin Listing 4-31 additions
  ===============================================
  */
  SimpleString a{ 50 };
  a.append_line("We apologize for the");
  SimpleString b{ 50 };
  b.append_line("Last message");

  // Show initial assignments of each object
  a.print("a");
  b.print("b");

  // Copy 'a' to 'b' and show new assignments.  Both have same statement: "We apologize for the"
  // most important: THAT MESSAGE RESIDES IN TWO SEPARATE MEMORY LOCATIONS
  b = a;
  a.print("a");
  b.print("b");

  /*
  OUTPUT
  Listing 4-31

  a: We apologize for the
  b: Last message
  a: We apologize for the
  b: We apologize for the
  */
  return 0;
}
