#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <cstring>
#include <iterator>
#include <type_traits>

#include "ch6.h"

using std::endl;
using std::getline;
using std::cin; using std::cout;

using std::size_t;

using std::string; using std::vector;
using std::begin; using std::end;

/*

Usage: (-O0 by default, you should try -O3 to learn more)

g++ -c double.cpp
g++ -c ch6-1.cpp
g++ double.o ch6-1.o -o double.out
./double.out

(for the example of constexpr/inline) g++ -c mul.cpp && g++ double.o mul.o ch6-1.o -o mul.out

*/

// case 2: (<- mul.cpp)
// int k = mul(1.0, 2.0);


int main() {

    double res = square(4.0);

    cout << res << endl;

    /* always define a constexpr/inline function in a header file */
    // case 1: (<- mul.cpp)
    cout << mul(2.0, 4.0) << endl;       // call (NOT inline): linker error if `mul` doesn't exist in the symbol table of `mul.cpp`

    return 0;
}

