#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <cstring>
#include <iterator>
#include <type_traits>

using std::endl;
using std::cin; using std::cout;

using std::string;
using std::vector;
using std::getline;
using std::begin;
using std::end;
using std::size_t;




int main() {

    int iarray_2d[3][4] = {{11}, {22}, {33}};

    int iarray_1d[4] = {222};
    // iarray_2d[1] = iarray_id;                               // illegal: expression must be a modifiable lvalue

    // decltype(iarray_id) iarray_1d_decl = {0, 1, 2, 3, 4};   // illegal: the #dim is included in the type of an array

    decltype(iarray_1d) iarray_1d_decl = {0, 1, 2, 3};         // Note: `iarray_id` is not an expression in the eyes of `decltype`
    decltype((iarray_1d)) iarray_1d_ref = iarray_1d;           // Note: now it's a reference

    decltype(iarray_2d) iarray_2d_decl = {};         // Note: `iarray_id` is not an expression in the eyes of `decltype`
    decltype((iarray_2d)) iarray_2d_ref = iarray_2d;           // Note: now it's a reference

    cout << "`typeid`: " << typeid(iarray_1d_decl).name() << endl;
    cout << "decltype(iarray_1d) -> `is_reference`: " 
         << std::is_reference<decltype(iarray_1d)>::value << " " << endl;
    cout << "decltype((iarray_1d)) -> `is_reference`: " 
         << std::is_reference<decltype((iarray_1d))>::value << " " << endl;

    cout << endl;

    cout << "`typeid`: " << typeid(iarray_2d_decl).name() << endl;
    cout << "decltype(iarray_2d) -> `is_reference`: " 
         << std::is_reference<decltype(iarray_2d)>::value << " " << endl;
    cout << "decltype((iarray_2d)) -> `is_reference`: " 
         << std::is_reference<decltype((iarray_2d))>::value << " " << endl;
    
    cout << endl;

    iarray_1d_ref[0] = 100;
    cout << "iarray_1d[0]: " << iarray_1d[0] << endl;

    iarray_2d_ref[2][3] = 100;
    cout << "iarray_1d[2][3]: " << iarray_2d[2][3] << endl;

    // if `iarray_2d` is set as a const (const int iarray_2d[3][4] ...), 
    // you will not be allowed to do that.

    cout << endl;

    /* Multi-dim array & array-2-pointer decay */
    for (decltype(iarray_2d[0]) row : iarray_2d) {          // Note: array-2-pointer disabled by `decltype`, expression & lvalue, type: int (&)[4]

        cout << "`typeid`: " << typeid(row).name() << " ";
        cout << "`is_reference`: " << std::is_reference<decltype(iarray_2d[0])>::value << " ";
        cout << "elems: ";

        for (auto &elem : row) {
            // elem = 100;
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "decltype(iarray_2d[0]+0) -> `is_reference`: " 
         << std::is_reference<decltype(iarray_2d[0]+0)>::value << " " << endl;

    cout << endl;

    for (decltype(iarray_2d[0]+0) row : iarray_2d) {        // Note: array arithmetic involved! "...+0" -> no ref (decltype) & int[4] -> int*

        cout << typeid(row).name() << " "         // type: Pi -> int* (converted by `auto`: int[4] -> int*)
             << typeid(*row).name() << " "        // type: i -> int
             << *row << endl;
    }

    // for (auto row : iarray_2d) {          // Note: array-2-pointer enabled by `auto`
    //     for (auto elem : row) {           // error: ‘begin’ was not declared in this scope
    //         cout << elem << " ";
    //     }
    //     cout << endl;
    // }

    cout << endl;

    for (auto row_first_elem_pt : iarray_2d) {                  // Note: array-2-pointer enabled by `auto`

        cout << typeid(row_first_elem_pt).name() << " "         // type: Pi -> int* (converted by `auto`: int[4] -> int*)
             << typeid(*row_first_elem_pt).name() << " "        // type: i -> int
             << *row_first_elem_pt << endl;
    }

    cout << endl;

    auto p = iarray_2d;                                 // Note: top-level const is discarded
    cout << typeid(p).name() << endl;                   // type: PA4_i -> int (*)[4]
    cout << typeid(iarray_2d[0]).name() << endl;        // type: int [4]

    cout << endl;

    /* One cannot change a multi-dim array row-wisely by using a reference to pointer */
    // error: a reference of type "int (*&)[4]" (not const-qualified) 
    // cannot be initialized with a value of type "int [3][4]"
    // int (*&p_ref)[4] = iarray_2d;
    int (*const&p_ref)[4] = iarray_2d;                  // Note: reference makes it a low-level const, which is NOT allowed to be discarded!
    cout << (*p_ref)[0] << endl;                        // eq: iarray_2d[0][0]
    cout << (*(p_ref+2))[3] << endl;                    // eq: iarray_2d[2][3]

    return 0;
}

