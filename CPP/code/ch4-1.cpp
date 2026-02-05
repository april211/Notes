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


int f();



int main() {

    int *p = nullptr, **p2p = &p;

    cout << "decltype ((&p)) -> `is_reference`: " 
         << std::is_reference<decltype ((&p))>::value << " " << endl;      // use `()` won't make `&p` become a lvalue
    cout << "decltype((p2p)) -> `is_reference`: " 
         << std::is_reference<decltype((p2p))>::value << " " << endl;

    cout << (*p2p == nullptr) << endl;

    cout << endl;

    vector<string> vss = {"", "april211"};
    auto vss_iter = vss.begin();
    cout << vss_iter++->empty() << endl;                         // precedence: `->` then `i++`, yields `true`
    cout << vss_iter->empty() << endl;                           // now it points to the 2nd, so it yields `false`

    string ss = "word";
    string ss_pl = ss + (ss[ss.size() - 1] == 's' ? "" : "s");   // Note: `ss[...]` gives you a char!
    // string ss_pl = ss + ss[ss.size() - 1] == 's' ? "" : "s";  // error: `==` compares string to char

    // order: `[...]` then `+` then `==` then `?:` then `=` (level 0)
    // eq: 
    // (ss_pl = (((ss + (ss[ss.size() - 1])) == 's') ? "" : "s"))

    cout << ss_pl << endl;

    int a = 0;

    // an opening `(` consumes the entire expression until the matching `)`
    typeid(a++);                   // parse as: `typeid((a++))` instead of `typeid(a)++` *due to the parentheses*

    // Also note: `a++` is NOT evaluated!

    cout << sizeof(vss).empty() << endl;               // parse as: `sizeof ((vss).empty())` <= `sizeof exp`

    // the compiler treats `(vss)` simply as 
    // "the variable `x` wrapped in grouping parentheses," not as a special "`sizeof` boundary."

    // sizeof a string or a vector: 
    // returns only the size of the fixed part of these types; 
    // it does NOT return the size used by the object’s elements.
    cout << sizeof(vss) << endl;                  // it shows `12`
    vss.push_back("april211");
    cout << sizeof(vss) << endl;                  // still shows `12`!

    int x[10];
    p = x;
    cout << sizeof(x)/sizeof(*x) << endl;         // the size of the array `x`
    cout << sizeof(p)/sizeof(*p) << endl;         // meaningless

    // gcc warning: division ‘sizeof (int*) / sizeof (int)’ does not compute the number of array elements

    int b = 1;
    cout << (sizeof a < b) << endl;               // `sizeof a`: 4, `b`: 1 < 4, false => 0
    cout << (sizeof (a < b)) << endl;             // `sizeof(bool)`: 1

    cout << (sizeof f()) << endl;

    /* comma op */
    vector<int> vi = {1, 2, 3, 4, 5};
    vector<int>::size_type cnt = vi.size();
    
    // prefix version
    for(vector<int>::size_type ix = 0; ix != vi.size(); ++ix, --cnt) {
        vi[ix] = cnt;
    }

//     // postfix version (both programs give the same result, but the prefix version is technically better)
//     for(vector<int>::size_type ix = 0; ix != vi.size(); ix++, cnt--) {
//         vi[ix] = cnt;
//     }

    cout << endl;

    // comma & conditional op
    bool cond = false;
    a = 0, b = 0;
    cond ? ++a, ++b : --a, --b;                   // eq: `(cond ? (++a, ++b) : --a), --b;`, `--b` is ALWAYS evalued!
    cout << a << " " << b << endl;

    return 0;
}

