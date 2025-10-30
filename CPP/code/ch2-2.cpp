#include <iostream>
using namespace std;




extern const int cint = 12;                      // valid

constexpr const int &cint_r = cint;              // valid: constexpr const, const binding address & const ref object
// constexpr int &cint_r = cint;                 // error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers (const vs constexpr)
constexpr const int *cint_p = &cint;             // valid: constexpr const, const pointer & const pointed object
// constexpr const int *const cint_p = &cint;    // also valid...
// constexpr int *cint_p = &cint;                // error: invalid conversion from ‘const int*’ to ‘int*’ (const vs constexpr)

int main() {

    // cint_p = &cint;                  // error: assignment of read-only variable ‘cint_p’
    // cint_r = -1;                     // error: assignment of read-only reference ‘cint_r’

    int ival = 4096;
    int &refVal = ival;                              // base type __ declarator

    cout << refVal << endl;

    int i = 512, &r1 = i; 
    double d = 3.14, &r2 = d;

    i = r2;

    cout << i << ' ' << &i << endl;                  // 3

    r1 = 1024;

    cout << r1 << ' ' << &r1 << endl;                // 1024

    r2 = r1;

    cout << r1 << ' ' << r2 << endl;                 // 1024 1024

    const int &crefVal_i = ival;                     // const int -> int (original!)
    const double &crefVal_d = ival;                  // const double -> int (const `temp` is created!)

    cout << &ival << ' ' << &crefVal_i << ' ' << &crefVal_d << endl;        // 0xffffc098 0xffffc098 0xffffc0f0

    int *pVal = &ival;
    double *pd = &d;

    cout << pVal << endl;

    pVal = nullptr;

    cout << pVal << endl;

    cout << *pd << endl;

    *pd = 11.14;

    cout << *pd << " " << *pd * *pd << " " << d << endl;                    // just a test for the priority of `*`... 

    void* vptr = &i;
    cout << "vptr: " << vptr << endl;
    vptr = &pd;
    cout << "vptr: " << vptr << endl;

    // pVal = pd;             // illegal: a value of type "double *" cannot be assigned to an entity of type "int *"
    // pd = pVal;             // illegal: error: cannot convert ‘int*’ to ‘double*’ in assignment
    // double *pd_i = pVal;   // illegal: error: cannot convert ‘int*’ to ‘double*’ in initialization
    // int* pVal_d = pd;      // illegal: error: cannot convert ‘double*’ to ‘int*’ in initialization

    // double **pd_null = nullptr;
    // pd = pd_null;                    // illegal: cannot convert ‘double**’ to ‘double*’ in assignment

    // double &*pdr = pd;  // illegal! (pointer to reference is not allowed)

    double *&pdr = pd;     // legal (a reference to the pointer, from inner to outer)

    cout << *pdr << endl;

    pdr = nullptr;

    cout << pd << endl;

    // double *&pdrt = nullptr;              // illegal! (a reference to a pointer can't be initialized by `nullptr`)
    // double *const&cpdr = nullptr;         // legal! (Note: with `const` & nullptr)
    double *const&cpdr = &d;                 // legal! (function param)
    // double *const&cpdr = pd;              // legal! (function param)

    if (!cpdr) {
        cout << "The pointer `cpdr` is `0`!" << endl;
    } else {
        cout << "The pointer `cpdr` is NOT `0`!" << endl;
    }

    // cpdr = nullptr;                       // illegal: assignment of read-only reference ‘cpdr’

    double *const*const top_const_ppd = &cpdr;      // legal: specifying `const` for each levels of a dual-level pointer
    cout << "**top_const_ppd: " << **top_const_ppd << endl;

    // extern const int cint_ill = 12;              // illegal!

    // ERROR: error: cannot convert ‘double*’ to ‘const int*’ in initialization
    // const int *ptr_ill = &d;                     // illegal: double &obj
    // const int *ptr_ill = pd;                     // illegal: double ptr

    // const int &const r3 = 1;                     // illegal!

    // const int i2 = 5, &r = i;                    // valid!
    // ++r;                                         // illegal: const int &r = i;

    const double *dptr_con;                         // valid! (Note: low-level const & no need to initialize the pointer)
    dptr_con = &d;
    cout << *dptr_con << endl;
    dptr_con = nullptr;
    cout << dptr_con << endl;

    const int i3 = 5;
    const int *clow_ptr = &i3;
    int *const chigh_ptr = &ival;
    int *iptr = &i;

    // iptr = clow_ptr;             // invalid (assign & low-level): error: invalid conversion from ‘const int*’ to ‘int*’
    iptr = chigh_ptr;               // valid!
    cout << "&iptr: " << &iptr << ' ' << "&*iptr: " << &*iptr << ' ' << "*iptr: " << *iptr << endl;

    cout << *chigh_ptr << endl;
    *chigh_ptr = 100;               // valid!
    cout << *chigh_ptr << endl;

    cout << *clow_ptr << endl;
    clow_ptr = chigh_ptr;           // valid!
    cout << *clow_ptr << endl;

    // https://stackoverflow.com/q/23281756/19336889
    // int null = 0;                           // under `-m64`: `warning: cast to pointer from integer of different size`
    long null = 0;                             // gives no warning, under `-m64` & `-m32`
    // const int null = 0;                     // gives no warning, under `-m64` & `-m32`
    // constexpr int null = 0;                 // gives no warning too, under `-m64` & `-m32`
    cout << "Size of the var `int`: " << sizeof(int) << endl;       // under `-m64`: 4, under `-m32`: 4
    cout << "Size of the type int*: " << sizeof(int*) << endl;      // under `-m64`: *8*, under `-m32`: 4
    cout << "Size of the type long: " << sizeof(long) << endl;      // under `-m64`: *8*, under `-m32`: 4
    int *iptr2 = (int*)(null);                 // The explicit conversion is crucial! (If `sizeof null == sizeof(int*)`, it gives no warning.)

    cout << iptr2 << endl;

    int i4 = 6;
    const int &r1_i4 = i4;
    // int &r2_i4 = r1_i4;                     // illegal: The low-level `const` must match!
    const int &r2_i4 = r1_i4;                  // illegal: The low-level `const` must match!

    cout << r1_i4 << " " << r2_i4 << endl;

    // constexpr int &ce_iref = ival;          // invalid: expression must have a constant value
    // const int &ce_iref = ival;              // valid!

    return 0;
}