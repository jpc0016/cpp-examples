/*
* CH4 Example
*
* simplestring-class.cpp
*
* Combining constructors, destructors, and exceptions; pages 107-113
*
* Listing 4-14, 4-15, 4-16, 4-17, 4-18, 4-19, 4-20, 4-21
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
    // Remember that print() uses the contents of buffer so its print statement looks like 'Constructed: x'
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
begin Listing 4-20 function definitions
===============================================
*/

void fn_c() {
  SimpleStringOwner c{ "cccccccccc" };    // This initialization throws an error due to lack of memory.
}

void fn_b(){
  SimpleStringOwner b{ "b" };
  fn_c();
}






int main() {
  /*
  ===============================================
  begin Listing 4-16 additions
  ===============================================
  */

  // Object initialization is moved to SimpleStringOwner struct definition

  // // initialize string of type SimpleString with a max_size of 115
  // SimpleString string{ 115 };
  //
  // // append lines to string
  // string.append_line("Starbuck, whaddya hear?");
  // string.append_line("Nothin' but the rain.");
  //
  // // PRINTS
  // // A: : Starbuck, whaddya hear?
  // // Nothin' but the rain.
  // string.print("A: ");
  //
  // string.append_line("Grab your gun and bring the cat in.");  // Append more text to string
  // string.append_line("Aye-aye sir, coming home.");
  //
  // // PRINTS
  // // B: : Starbuck, whaddya hear?
  // // Nothin' but the rain.
  // // Grab your gun and bring the cat in.
  // // Aye-aye sir, coming home.
  // string.print("B: ");
  //
  // // this message prints if append_line determines SimpleString has run out of space
  // if(!string.append_line("Galactica!")) {
  //   printf("String was not big enough to append to another message.\n");
  // }

  /*
  ===============================================
  begin Listing 4-19 addition
  ===============================================

  OUTPUT

  Constructed: x
  x is alive
  About to destroy: x
  */

  // The string value in x is what changes throughout the object's life cycle
  //SimpleStringOwner x{ "x" };
  //printf("x is alive\n");
  // since x is an Automatic variable, it is destroyed just before main() returns


  /*
  ===============================================
  begin Listing 4-20 lines
  ===============================================

  Call Stack Unwinding
  */

  try {
    SimpleStringOwner a{ "a" };
    fn_b();
    SimpleStringOwner d{ "d" };
  } catch(const std::exception& e) {
    printf("Exception: %s\n", e.what());
  }

  /*
  OUTPUT

  Constructed: a
  Constructed: b
  About to destroy: b
  About to destroy: a
  Exception: Not enough memory!
  */


  return 0;
}
