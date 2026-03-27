#include "ch6.h"



// illegal: should be defined in the header file!
constexpr double mul(double x, double y) { return x* y; };
// inline double mul(double x, double y) { return x* y; };

/* to verify the existence & usage of the weak symbol `mul` */

// case 1: 
// use constexpr func.: inlined! weak symbol NOT generated! (constexpr forced the calc., -O0, not -O3!)
// use inline func.: NOT inlined! weak symbol generated! (-O0, not -O3!)
// int k = mul(1.0, 2.0);

// constexpr var. & inline (not constexpr) func. -> compile error
// constexpr int k = mul(1.0, 2.0);


int main(){

    // case 2:
    // use constexpr func.: inlined! (Constant Folding) weak symbol NOT generated! (-O0, not -O3!)
    // use inline func.: NOT inlined! weak symbol generated! (-O0, not -O3!)
    // int k = mul(1.0, 2.0);

    // NOT inlined! weak symbol generated! (-O0, not -O3!)
    // mul(1.0, 2.0);               // constexpr: Constant Folding skipped (not init.)!!

    // case 3:
    // assume constexpr func. is used now
    constexpr double d1 = 1.0, d2 = 2.0;            // inlined! weak symbol NOT generated! (-O0, not -O3!)
    // double d1 = 1.0, d2 = 2.0;                   // NOT inlined! weak symbol generated! (-O0, not -O3!)
    int k = mul(d1, d2);                            // the lesson: Constant Folding requires constexpr inputs!

    return 0;
}

