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

typedef string string_arr[10];

string ssarr[10] = {};

/* a function that returns a reference to an array of ten strings */
string (&func_return_ssarr_ref_C(const vector<string>&))[10];
string_arr& func_return_ssarr_ref_def(const vector<string>&);
decltype(ssarr)& func_return_ssarr_ref_decl(const vector<string>&);
auto func_return_ssarr_ref_trail(const vector<string>&) -> string (&)[10];          //  C++ style & clear, preferred


/* default arguments */
double add(double x, double y = 1.0) {return x + y;}         // A definition is also a declaration.
double add(double = 2.0, double);                            // add a default arg for the declared function
// double add(double, double = 99.0);                        // error: default argument given for parameter 2
double add(double, double);                                  // still: double add(double x = (2.0), double y = (1.0))

// double add(double, double);                               // compilation passed (exactly the same)
// const double add(double, double);                         // error: ambiguating new declaration of ‘const double add(double, double)’

// error: redeclaration ‘constexpr double add(double, double)’ 
// differs in ‘constexpr’ from previous declaration
// constexpr double add(double, double);

constexpr double minus(double x, double y = 1.0) {return x - y;}         // implicit inline
constexpr double minus(double x = 2.0, double y);                        // implicit inline

// constexpr double notdefined_func(double, double);                     // compilation passed

string make_plural(size_t ctr, const string &word, const string &ending = "s") {        // Note: not 's' (char)! `{1, 's'}` is OK.
    return (ctr > 1) ? word + ending : word; 
}

typedef decltype(add) Func;
// using Func = decltype(add);
void test_func_type_param(Func);               // param conversion: Func -> Func*

int (*func_rt_pf(int))(int*, int);             // a function that returns a *pointer* to a function
// int ((*func_rt_func)(int))(int*, int);      // illegal: a function pointer that points to the *function type* `int(int*, int)`

// define a pointer to an array using `using` & port it into the return type
using array_pt_T = int(*)[10];
array_pt_T pt2array = nullptr;
array_pt_T test_func_return_p2a();


int main() {

    cout << add() << endl;
    cout << minus() << endl;

    cout << endl;

    const string ss_200 = "success";
    const string ss_404 = "faliure";

    cout << make_plural(ss_200.size(), ss_200, "es") << endl;
    cout << make_plural(ss_404.size(), ss_404) << endl;             // use the default arg of param `ending`
    cout << make_plural(ss_200.size(), ss_200, "") << endl;
    cout << make_plural(ss_404.size(), ss_404, "") << endl;

    // define a reference/pointer to a function
    Func& ref2func = add;
    Func* pt2func = add;                                // Note: `&` is optional!
    // Func* pt2func = &add;

    cout << ref2func(12.0, 23.0) << endl;
    cout << pt2func(12.0, 23.0) << endl;                // Note: automatically dereferenced!
    cout << (*pt2func)(12.0, 23.0) << endl;

    // illegal: const_reference cannot be overloaded with reference
    // address( double(&)(double, double) ) <--> address( double(&)(double, double) )
    // In C++, functions are inherently read-only. 
    // You cannot modify a function's code at runtime. 
    // Therefore, adding const to a function type does absolutely nothing.
    // vector<Func> func_vec;

    vector<Func*> func_pt_vec = {add, add};
    // vector<double (*)(double, double)> func_pt_vec = {add, add};
    // vector<decltype(add)*> func_pt_vec = {add, add};
    for(auto temp : func_pt_vec) {
        cout << temp(34.0, 45.0) << endl;
    }

    return 0;
}
