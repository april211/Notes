#include <iostream>
#include "sales_item.h"
using namespace std;


using INTR = int&;

int c_global = 9;
const int ccst_global = 99;

int main() {

    int a = 1, b = 2;
    const int ccst = 3;

    // reference is kept by `decltype`
    int &aref = a;
    decltype(aref) decl_aref = a;                           // `decl_aref`: int &

    cout << aref << ' ' << decl_aref << endl;

    // top-level const: const, constexpr, alias
    constexpr int ce_a = ccst;
    int *const ctop_iptr = &a;
    constexpr int *cetop_iptr = &c_global;
    const INTR iref = b;
    constexpr INTR ce_iref = c_global;

    // `constexpr` seems to be a one-time thing... (just a "check" -> implicit `const`)
    // the meaningful & implicit `const` is kept though... 
    decltype(ce_a) decl_ca = a;                             // Note: top-level `constexpr` -> top-level `const`!
    decltype(ctop_iptr) decl_ctop_iptr = &b;                // `decl_c_iptr`: int *const (top-level `const` is kept!)
    decltype(cetop_iptr) decl_cetop_iptr = &c_global;       // `decl_ce_iptr`: int *const (from constexpr int *, which is a top-level const)
    decltype(iref) decl_iref = b;                           // "useless" const recognized!
    decltype(ce_iref) decl_ce_iref = a;                     // Note: `constexpr` is discarded! (constexpr INTR ce_iref -> const INTR ce_iref, "useless")

    cout << decl_ca << endl;
    cout << *decl_ctop_iptr << ' ' << *decl_cetop_iptr << endl;
    cout << decl_iref << ' ' << decl_ce_iref << endl;

    // the low-level const is also kept.
    const int *clow_iptr = &a;
    const int &clow_iref = b;

    decltype(clow_iptr) decl_captr = &a;
    decltype(clow_iref) decl_caref = a;

    // *decl_captr = -1;                                       // illegal: error: assignment of read-only location ‘* decl_captr’
    // decl_caref = -1;                                        // illegal: error: assignment of read-only reference ‘decl_caref’

    cout << *decl_captr << ' ' << decl_caref << endl;

    // `decltype` can deduce from an `auto` var.
    auto auto_a = decl_ca;                                     // top-level `const` is discarded
    decltype(auto_a) auto_decl_a = a;

    cout << auto_a << ' ' << auto_decl_a << endl;

    // `decltype` + class + expression & reference
    Sales_item item1, item2;
    decltype(item1 + item2) item3;                             // `item_` is NOT a reference!

    cout << item3 << endl;

    decltype(*clow_iptr) decl_exp_aref = a;                    // `decl_exp_aref` IS a reference!
    decltype(*clow_iptr + 0) decl_exp_a = a;                   // `decl_exp_a` is NOT a reference!
    decltype(1/0) decl_exp_b = b;                              // legal! (not evaluated, int)
    // decltype((1/0)) decl_exp_b = b;                         // legal! (not evaluated, int, w/o any warning & error)
    decltype((b)) decl_exp_bref = b;                           // legal! (not evaluated, Note: int&!)

    // illegal! (evaluated, compile warning: division by zero, Runtime Error: Arithmetic exception)
    // auto illi = 1/0;

    // cout << 1 / 0 << endl;                                  // illegal: Arithmetic exception (runtime)

    cout << decl_exp_aref << ' ' << decl_exp_a << ' ' << decl_exp_b << ' ' << decl_exp_bref << endl;

    // Exercise 2.37: assignment also cause `decltype` to return a reference type
    decltype(a = b) d = a;                                      // `a` won't be change by `decltype(a = b)`

    cout << a << ' ' << b << ' ' << d << endl;

    return 0;
}