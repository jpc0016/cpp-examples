/*
* CH4 Example
*
* destructor-exceptions.cpp
*
* Handling exceptions in destructors; pages 106-107
*
* Throwing exceptions in destructors is dangerous. If an exception is thrown in
* a destructor, it must be catched in the same destructor block or two exceptions could
* be in flight.
*
* Listing 4-13
*
*/

#include <cstdio>
#include <stdexcept>

// struct holds a constructor printing a simple message. It's destructor throws an uncaught exception.
struct CyberdyneSeries800 {
  CyberdyneSeries800(){
    printf("I am a friend of Sarah Connor.");   // This does not print. The compiler has a hang-up with the thrown exception
  }
  ~CyberdyneSeries800(){
    throw std::runtime_error{ "I'll be back." };
  }
};


int main(){

  try {
    // initialize CyberdyneSeries800 object and throw std runtime_error message
    CyberdyneSeries800 t800;
    throw std::runtime_error{ "Come with me if you want to live." };
  } catch(const std::exception& e) {
    // e.what() is the error message thrown.
    printf("Caught exception: %s\n", e.what());
  }



  return 0;
}

/*
CLANG++ OUTPUT

destructor-exceptions.cpp:24:5: warning: '~CyberdyneSeries800' has a non-throwing exception specification but can still throw [-Wexceptions]
    throw std::runtime_error{ "I'll be back." };
    ^
destructor-exceptions.cpp:23:3: note: destructor has a implicit non-throwing exception specification
  ~CyberdyneSeries800(){
  ^
1 warning generated.

======================================================================================================================================

OUTPUT

terminate called after throwing an instance of 'std::runtime_error'
  what():  I'll be back.
Aborted (core dumped)

*/
