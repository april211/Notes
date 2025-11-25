#include <iostream>
#include <typeinfo>                     // Gemini: Required for typeid
using namespace std;


/* C */
// typedef int INT, *int_pointer;
// typedef int ARRAY_INT[10];
// typedef int &INTR;
// typedef const int &CINTR;

/* C++ 11 */
using INT = int;
using int_pointer = int*;               // Note: compare the one above using `typedef`
using cint_pointer = const int*;
using ARRAY_INT = int[10];              // Note: compare the one above using `typedef`
using INTR = int&;                      // Note: compare the one above using `typedef`
using CINTR = const int&;               // Note: compare the one above using `typedef`

int c = 10;
const int ccst_global = 7;                         // address fixed & has constant value!

int main() {

    int a = 1, b = 2;
    int_pointer iptr_1 = &a, iptr_2 = &b;          // no need to specify `*` for each pointer

    cout << sizeof(INT) << " " << sizeof(int) << endl;
    cout << sizeof iptr_1 << " " << sizeof iptr_2 << endl;
    cout << *iptr_1 << " " << *iptr_2 << endl;

    const int ccst = 6;
    // int_pointer iptr2c = &ccst;                 // error: invalid conversion from ‘const int*’ to ‘int_pointer’
    // const int_pointer iptr2c = &ccst;           // error: &ccst (low-level const) -> const int_pointer (top-level)
    cint_pointer iptr2c = &ccst;                   // valid!
    cout << "*iptr2c: " << *iptr2c << endl;

    ARRAY_INT array;

    cout << sizeof array << endl;

    double nd = 1.87;
    auto id = a + nd;
    cout << typeid(a).name() << ' ' << typeid(nd).name() << endl;
    cout << typeid(id).name() << ' ' << id << endl;     // `d` for `double`

    // auto ntype;              // illegal: cannot deduce 'auto' type (initializer required)

    int *iptr = &a;
    auto ptr = iptr;            // type: pointer
    // auto *pp = &iptr;        // type: pointer to a pointer (complete the declarator)
    auto pp = &iptr;            // type: pointer to a pointer
    // auto *ptr = &a;          // Note: pointer to an int!
    auto &ref = a;              // type: reference (explicitly modified)

    cout << *ptr << " " << **pp << " " << ref << endl;

    /* types (including modifiers) must be consistent with each other */
    // auto i = 0, p = &i;      // 'auto' type is "int *" for this entity, but was previously implied to be "int"

    // top-level const is ignored
    int *const ctop_iptr_init = &a;
    const int *const cboth_iptr_init = &a;
    auto ptr_nc = ctop_iptr_init;                // top-level `const` is discarded
    auto ptr_lc = cboth_iptr_init;               // top-level `const` is discarded, but low-level `const` is kept
    const auto ptr_tc = ctop_iptr_init;          // *top-level* `const` is manually added
    const auto ptr_cc = cboth_iptr_init;         // *top-level* `const` is manually added, low-level `const` is kept

    cout << *ptr_nc << " " << *ptr_lc << " " << *ptr_tc << *ptr_cc << endl;

    // Step 1. deduce the type in the place of `auto`
    // Step 2. regard the base type and the possible modifiers *as a whole*
    // Step 3: `const` qualifies `auto` type *as a whole*
    const auto ctop_iptr = &b;      // Note: *top*-level! similar to constexpr/alias -> pointer (const -> auto: int*, res: int *const)
    cout << *ctop_iptr << endl;
    ++*ctop_iptr;                   // valid: int *const ctop_iptr (const is top-level instead of low-level)
    cout << *ctop_iptr << endl;
    cout << b << endl;
    // ++ctop_iptr;                 // error: increment of read-only variable ‘ctop_iptr’

    const auto *clow_iptr = &b;     // Note: *low*-level! (const -> auto: int, res: const int *)
    cout << *clow_iptr << endl;
    // ++*clow_iptr;                // error: increment of read-only location ‘* clow_iptr’
    // cout << *clow_iptr << endl;
    // cout << b << endl;
    ++clow_iptr;                    // valid!

    const auto *const cboth_iptr = &b;     // Note: *both*-level! (const int *const)
    cout << *cboth_iptr << endl;
    // ++*cboth_iptr;                      // error: increment of read-only location ‘* clow_iptr’
    // cout << *cboth_iptr << endl;
    // cout << b << endl;
    // ++cboth_iptr;                       // also invalid!

    const auto &cref = 8;           // valid: const int &cref
    // const auto &cref = 4* b;     // valid: const int &cref
    // auto &cref = 8;              // invalid: int &cref
    // auto &cref = b* 4;           // invalid: int &cref
    cout << cref << endl;

    const INTR iref = a;                         // "top-level": for ref: "useless"; for pointer: const pointer
    cout << a << endl;
    ++iref;                                      // valid!!!
    cout << a << endl;

    // constexpr INTR iref_ce = a;               // invalid: expression must have a constant value
    constexpr INTR iref_ce = c;                  // valid: INTR -> type of `c`, constexpr -> *fixed address* of `c` (global) & "top-level" const
    cout << c << endl;
    ++iref_ce;                                   // valid!
    cout << c << endl;

    constexpr int_pointer ipt_ce = &c;           // valid: constexpr -> *fixed address* of `c` (global) & top-level const
    cout << *ipt_ce << endl;
    // ipt_ce = nullptr;                         // invalid: assignment of read-only variable ‘ipt_ce’

    // constexpr INTR iref_ce = a;               // invalid: expression must have a constant value
    // constexpr INTR iref_ce = ccst;            // invalid: "INTR" (aka "int &") to initializer of type "const int"
    // constexpr CINTR iref_ce = ccst;           // invalid: expression must have a constant value (constexpr, ref: *fixed address*)
    // constexpr CINTR iref_ce = ccst_global;    // valid: const int & -> const int, constexpr -> global *fixed address*
    // cout << c << endl;
    // ++iref_ce;                                // invalid: increment of read-only reference ‘iref_ce’
    // cout << c << endl;

    // CINTR ciref = a;                      // that's the only way!
    // cout << a << endl;
    // ++ciref;                              // error: increment of read-only reference ‘ciref’ (expected)
    // cout << a << endl;

    // constexpr CINTR ciref_ce = c;         // valid: const int & -> int, constexpr -> global *fixed address*
    // cout << c << endl;
    // ++ciref_ce;                           // error: increment of read-only reference ‘ciref_ce’ (expected)
    // cout << c << endl;

    // try to define a reference to a pointer using self-defined alias
    // int *&iptref = &a;                  // invalid: initial value of reference to non-const must be an lvalue
    // const int *&iptref = &a;            // invalid: initial value of reference to non-const must be an lvalue
    // int *const&iptref = &a;             // valid: *const (top-level, `&a` is a literal)
    // int *&iptref = iptr_1;              // valid: a typical definition
    // int_pointer &iptref = &a;           // invalid: initial value of reference to non-const must be an lvalue
    const int_pointer &iptref = &a;        // valid: const -> int_pointer (also top-level!)
    // const int_pointer &iptref = &ccst;  // invalid: invalid conversion from ‘const int*’ to ‘int_pointer’ {aka ‘int*’} 
    cout << *iptref << endl;

    // const ref != constexpr ref
    // const auto &c_auto_iref = 1;              // valid: ref to const
    const auto &c_auto_iref = a* 4;              // valid: ref to const
    // constexpr auto &ce_auto_iref = 1;         // invalid: constexpr can't bind literals & expressions (constexpr vs const)
    // constexpr auto &ce_auto_iref = 4* c;      // invalid: constexpr can't bind literals & expressions (constexpr vs const)
    // constexpr auto &ce_auto_iref = c;         // valid: constexpr int&
    constexpr const auto &ce_auto_iref = c;      // valid: constexpr -> *ref* (`c`'s address is fixed), const -> `ce_auto_iref`'s value
    // constexpr int &ce_auto_iref = c;                // vaild, but `c` can be changed through `ce_auto_iref`!!
    // constexpr auto &ce_auto_iref = ccst_global;     // valid: auto infered from `const int ccst_global`

    // ++ce_auto_iref;                                 // vaild if `constexpr int &ce_auto_iref = c;` or `constexpr auto &ce_auto_iref = c;`

    cout << c_auto_iref << " " << ce_auto_iref << endl;

    // constexpr const auto ce_c_auto_i = 5;           // valid: -> `constexpr int`
    // constexpr auto ce_auto_i = ccst;                // valid: -> `constexpr int` (`ce_auto_i` is NOT a reference!)
    // ++ce_c_auto_i;                                  // error: increment of read-only variable ‘ce_c_auto_i’
    // ++ce_auto_i;                                    // error: increment of read-only variable ‘ce_auto_i’
    // constexpr auto ce_c_auto_i = a;                 // invalid: error: the value of ‘a’ is not usable in a *constant expression*
    const auto ce_c_auto_i = a;                        // valid: `const` can binds to a non-const object, while `constexpr` can't!
    cout << ce_c_auto_i << endl;

    // auto & alias
    auto &ali_auto_iref = iref;                        // `iref`: `INTR`(int&), `ali_auto_iref`: int&
    auto ali_auto_iptr = clow_iptr;                    // `clow_iptr`: `const int *`, `ali_auto_iptr`: `const int *`

    cout << ali_auto_iref << endl;
    cout << *ali_auto_iptr << endl;

    // auto & constexpr: the `constexpr` in an initializer always apply a top-level `const`, 
    // which will be discarded during `auto` deduction.

    // Exercise 2.35
    // const int i = 42;
    // auto j = i;
    // const auto &k = i;
    // auto *p = &i;
    // const auto j2 = i, &k2 = i;

    return 0;
}