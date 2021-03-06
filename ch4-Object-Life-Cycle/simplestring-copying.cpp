/*
* CH4 Example
*
* simplestring-copying.cpp
*
* Copy constructors; pages 117-118
* Handles memberwise copy of fully featured classes to avoid double free
*
* Listing 4-25, 4-26, 4-27
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
  begin Listing 4-25 additions
  ===============================================
  */

  // copy-Constructor with member initializers
  SimpleString(const SimpleString& other)
    : max_size{ other.max_size },           // max_size attribute of other SimpleString object assigned to current instance of max_size
      buffer{ new char[other.max_size] },   // same with current instance of buffer. 'new char[max_size]' is original initialization of buffer
      length{ other.length } {              // length attribute of other SimpleString object assigned to current instance of length
      /* This is the body of constructor. It holds a strncpy statement that copies contents
      pointed to by other.buffer into an array pointed to by current buffer instance */
      std::strncpy(buffer, other.buffer, max_size);
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


/*
===============================================
begin Listing 4-27 additions
===============================================

Does not append string because SimpleString object is passed BY VALUE and not BY REFERENCE
Use 'SimpleString& x' to pass fully featured objects. Use a const reference if you can.  See line
51 on why you cannot use 'const'
*/
void foo(SimpleString& x) {
  // below line prints if buffer is large enough and object is passed BY REFERENCE
  x.append_line("This change is lost.");
}

int main() {

  /*
  ===============================================
  begin Listing 4-26 additions
  ===============================================

  Creating SimpleString object 'a' then copying 'a' by initializing another
  SimpleString object with 'a' as input.
  */
  // SimpleString a{ 50 };                   // initializes original SimpleString object with max_size = 50
  // a.append_line("We apologize for the");
  // SimpleString a_copy{ a };               // uses copy-constructor with a SimpleString object (a) as input
  // a.append_line("inconvenience.");        // appears on new line due to 'buffer[length++] = '\n';'
  // a_copy.append_line("incontinence.");
  //
  // // print objects
  // a.print("a");
  // a_copy.print("a_copy");

  /*
  ===============================================
  More Listing 4-27 additions
  ===============================================

  Does not append string because SimpleString object is passed BY VALUE and not BY REFERENCE
  Use 'const SimpleString& x' (a const reference) to pass fully featured objects
  */
  SimpleString a{ 20 };
  foo(a);                       // passes object to foo which is accessed BY REFERENCE
  a.print("Still empty");       // Listing 4-27 OUTPUT: 'Still empty:'

  /*
  OUTPUT
  Listing 4-26

  a: We apologize for the
  inconvenience.
  a_copy: We apologize for the
  incontinence.
  */
  return 0;
}
