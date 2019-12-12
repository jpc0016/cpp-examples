/*
* CH4 Example
*
* move-semantics.cpp
*
* Moving objects instead of copying; pages 126-129
* Copying is often wasteful.  After moving from an object, the object is said to
* be in a "moved-from" state.  It can only be reasigned or destructed.
*
* Listing 4-38
*
*/

#include <cstdio>
#include <cstring>
#include <stdexcept>
