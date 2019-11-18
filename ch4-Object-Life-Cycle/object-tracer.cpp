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

  // Uncovered errata here: https://github.com/JLospinoso/ccc/issues/44
  const auto t2_ptr = &t2;

  printf("A\n");
  Tracer t3{ "Automatic variable" };  // Automatic variable is destructed at the end of main().  Automatic variables have a scope of main()

  printf("B\n");
  const auto t4 = new Tracer{ "Dynamic variable" };

  printf("C\n");
}
// static and thread_local variables are destructed just before program exit

/*
OUTPUT GENERATED

Static variable constructed.
Thread-local variable constructed.
A
Automatic variable constructed.
B
Dynamic variable constructed.
C
Automatic variable destructed.
Thread-local variable destructed.
Static variable destructed.

*/
