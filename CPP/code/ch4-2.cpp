#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <cstring>
#include <iterator>
#include <type_traits>

using std::endl;
using std::getline;
using std::cin; using std::cout;

using std::size_t;

using std::string; using std::vector;
using std::begin; using std::end;


int main() {

    const string *ps = nullptr;
    void* pv = nullptr;

    // pv = (void*)ps;                                      // the old style: valid
    pv = static_cast<string*>(const_cast<string*>(ps));     // the new style: clearer & also valid (recommended)

    cout << (pv == nullptr) << endl; 

    return 0;
}

