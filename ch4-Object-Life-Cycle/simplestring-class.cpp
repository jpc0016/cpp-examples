/*
* CH4 Example
*
* simplestring-class.cpp
*
* Combining constructors, destructors, and exceptions; pages 107-111
*
* Listing 4-14, 4-15, 4-16
*
*/

#include <cstdio>
#include <stdexcept>

struct SimpleString {
  SimpleString(size_t max_size)
    : max_size{ max_size },
     length{} {
       if (max_size == 0) {
         throw std::runtime_error{ "Max size must be at least 1." };
       }
       buffer = new char[max_size];
       buffer[0] = 0;
  }

  ~SimpleString(){
    delete[] buffer;
  }

private:
  size_t max_size;
  char* buffer;
  size_t length;
};


int int main() {
  /* code */
  return 0;
}
