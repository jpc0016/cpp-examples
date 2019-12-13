/*
* CH4 Example
*
* move-semantics-simplestring.cpp
*
* Moving objects instead of copying; pages 126-129
* Copying is often wasteful.  After moving from an object, the object is said to
* be in a "moved-from" state.  It can only be reasigned or destructed.
*
* Listing 4-35, 4-36, 4-37, 4-38
*
* Using SimpleString class again; Listing 4-38 is a rollup of the entire SimpleString class with
* all copy and move constructors
*/

#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

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
  begin Listing 4-25 additions
  ===============================================

  copy-Constructor with member initializers
  */
  SimpleString(const SimpleString& other)
    : max_size{ other.max_size },
    buffer{ new char[other.max_size] },
    length{ other.length } {
    std::strncpy(buffer, other.buffer, max_size);
  }


  /*
  ===============================================
  begin Listing 4-35 additions
  ===============================================

  move-constructor uses rvalue references instead of lvalue references
  Use 'noexcept' because compilers cannot use exception-throwing constructors and will resort to
  copy-constructors instead.
  */
  SimpleString(SimpleString&& other) noexcept
    : max_size{ other.max_size },
    buffer(other.buffer),
    length(other.length) {

    // Can change other's values since other is an rvalue reference
    other.length = 0;
    other.buffer = nullptr;
    other.max_size = 0;
  }


  /*
  ===============================================
  begin Listing 4-29 and 4-30 additions
  ===============================================

  copy-constructor using copy assignment operator (operator=)
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



  /*
  ===============================================
  begin Listing 4-36 additions
  ===============================================

  create move analogue to copy assignment using operator=
  */
  SimpleString& operator=(SimpleString&& other) noexcept {
    if (this == &other) return *this;   // simple self-reference check.  Return current object 'this' if all attributes are equal
    delete[] buffer;          // clean up buffer before assigning fields of this to fields of other.
    buffer = other.buffer;
    length = other.length;
    max_size = other.max_size;

    // zero out attributes of other to set to destructive state
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;
    return *this;
  }



/*
===============================================
begin Listing 4-15 functions print() and append_line()
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

  // Listing 4-36.5
  // Define move-constructor here using an rvalue
  // x is an rvalue reference but std::move() is required because x is a moved-from object.  This makes x an lvalue
  SimpleStringOwner(SimpleString&& x) : string{ std::move(x) } {}

private:
  SimpleString string;
};


int main() {

  /*
  ===============================================
  begin Listing 4-37 additions
  ===============================================
  */
  SimpleString a{ 50 };
  a.append_line("We apologize for the");
  SimpleString b{ 50 };
  b.append_line("Last message");

  // verify the strings before moving
  a.print("a");
  b.print("b");

  // move a into b.  a is "moved-from" and cannot be used unless reassigned new values
  b = std::move(a);   // cast 'a' to an rvalue using std::move()
  b.print("b");


  /*
  OUTPUT
  Listing 4-37

  a: We apologize for the
  b: Last message
  b: We apologize for the
  */
  return 0;
}
