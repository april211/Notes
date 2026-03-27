#ifndef CH6_H
#define CH6_H


// Don't DEFINE a function that is neither a `constexpr` nor `inline` inside a header file!
// We must follow the rule of ODR (One Definition Rule) in this case!
// Both `constexpr` and `inline` are special cases...
double square(double x);            // from ch6-1.cpp


// compilation warning: inline function ‘constexpr double mul(double, double)’ used but never defined
constexpr double mul(double, double);
// inline double mul(double, double);
// constexpr double mul(double x, double y) { return x* y; };


// The source file that defines a function should include the header that contains that function’s declaration. 
// That way the *compiler* will verify that the definition and declaration are consistent. (P305)
// Checked items: return type, inline/constexpr, noexcept
// Ignored items: top-level const on params
// It fails when: overloadding (compilation pass, but linker will be likely to complain)

#endif