/*
* CH4 Example
*
* object-tracer.cpp
*
* Tracing the object life cycle; pages 97-98
*
* Tracer example; listing 4-5 and 4-6
*
*/

#include <cstdio>
#include <thread>

// Traces the life cycle of an object by announcing object creation and object destruction
struct Tracer {

  // constructor takes parameter 'name' and saves it into the member 'name' using :
  Tracer(const char* name) : name{ name } {
    printf("%s constructed.\n", name);
  }

  ~Tracer() {
    printf("%s destructed.\n", name);
  }

private:
  // Both the pointed-to value AND the pointer cannot change
  // See:  https://stackoverflow.com/questions/890535/what-is-the-difference-between-char-const-and-const-char
  const char* const name;
};


static Tracer t1{ "Static variable" };
thread_local Tracer t2{ "Thread-local variable" };  // keyword 'static' assumed when using only 'thread_local'


int main() {

  printf("A\n");
  Tracer t3{ "Automatic variable" };

  printf("B\n");
  const auto t4 = new Tracer{ "Dynamic variable" };

  printf("C\n");
}

/*
OUTPUT GENERATED



*/
