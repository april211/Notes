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

Usage:

g++ -c double.cpp
g++ -c ch6-1.cpp
g++ double.o ch6-1.o -o double.out
./double.out

*/


int main() {

    double res = square(4.0);

    cout << res << endl;

    return 0;
}

