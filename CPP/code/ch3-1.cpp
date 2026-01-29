#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <cstring>
#include <iterator>

using std::endl;
using std::cin; using std::cout;

using std::string;
using std::vector;
using std::getline;
using std::begin;
using std::end;



int main() {

    string ss1 = "april211";            // copy init, the `NULL` is NOT included
    string ss2(12, 'A');                // direct init
    cout << ss1 << ' ' << ss2 << endl;

    /* The string input operator reads and discards any leading whitespace (e.g., spaces, newlines, tabs). */
    // string ss_input;
    // cin >> ss_input;                 // " Hello World!" -> "Hello"
    // cout << ss_input << endl;

    // string word;
    // while (cin >> word) {            // "aub cdh" -> "aub", "cdh"
    //     // cout << word;
    //     cout << word << endl;
    // }

    // string line;
    // while (getline(cin, line)) {     // Note: The Linux console treat `\n` as `\` and `n` literally.
    //     cout << line;
    // }

    // string::size_type ss2_size = ss2.size();         // always store it using `string::size_type`
    // auto ss2_size = ss2.size();                      // preferred, the actual type: `std::size_t`
    decltype(ss2.size()) ss2_size = ss2.size();         // alternative: use `std::size_t`
    cout << ss1.empty() << ' ' << ss2_size << endl;

    /* String assignment */
    string ss3 = "STL";
    ss3 = ss2;          // a copy of ss2
    ss3[2] = 'K';
    cout << "ss3: " << ss3 << ", ss2: " << ss2 << endl;         // ss2 is NOT changed

    /* String concatnation*/
    ss3 = "00" + ss3;                                           // putting char[] first is also acceptable
    cout << "ss3: " << ss3 << endl;

    // const string s = "Keep out!"; for (auto &c : s) {}       // const char &c

    /* C-style string concat */
    const char css1[] = {'A', 'B', 'C', '\0'};
    const char css2[] = {'D', 'E', '\0'};
    // const int csz = strlen(css1) + strlen(css2) + 1;         // `constexpr` is NOT necessary on GCC + Linux
    // constexpr int csz = strlen(css1) + strlen(css2) + 1;     // illegal: expression must have a constant value
    constexpr int csz = 6;
    char css3[csz] = {};                                        // Note: filled with '\0'!

    // Use `strcat`
    cout << "Use `strcat`: " << endl;

    // css3 = strcat(css3, css1);                               // error: expression must be a modifiable lvalue
    char *pt_css3 = strcat(css3, css1);                         // `pt_css3` can be omitted here
    pt_css3 = strcat(css3, css2);

    for(const auto& ch : css3) {
        if (ch == '\0') {
            break;                                      // stop at the first '\0'
        }
        cout << ch;
    }

    cout << endl;

    // char *pt_begin = begin(pt_css3);                         // illegal: T* begin( T (&array)[N] );

    for(char *pt_ch = pt_css3; pt_ch < pt_css3+csz; ++pt_ch) {
        if (*pt_ch == '\0') {
            break;                                      // stop at the first '\0'
        }
        cout << *pt_ch;
    }

    cout << endl;

    // Use `strcpy`
    cout << "Use `strcpy`: " << endl;

    memset(css3, 0, csz);

    strcpy(css3, css1);
    pt_css3 = css3+strlen(css1);                                // Note: use the array arithmetic to obtain the new start point
    strcpy(pt_css3, css2);

    for(const auto& ch : css3) {
        if (ch == '\0') {
            break;                                      // stop at the first '\0'
        }
        cout << ch;
    }

    cout << endl;

    // warning: ISO C++ forbids converting a string constant to ‘char*’
    // char *pp_str = "XXX";
    const char *pp_str = "XXX";                                 // C++ always automatically appends a null terminator to string literals.
    cout << *pp_str << endl;
    // *pp_str = 'Y';                                           // Segmentation fault (w/o `const`) or error (w/ `const`): Read-Only Data
    if (*(pp_str+3) == '\0') {
        cout << "`\\0` appended!" << endl;
    }

    // Strictly speaking, assigning a const char* to a char* is illegal 
    // because you are discarding the const qualifier.
    // To keep millions of lines of old code from breaking, 
    // C++ compilers historically allowed this "conversion" as a special exception.

    char css4[] = "String Literal";                     // Note: `css4` is a COPY of the given string literal ({...}, Syntactic Sugar)
    // The fact that those values came from a string literal doesn't restrict the array itself.

    // char ccss[] = css4;                              // illegal: one cannot init an array using another array
    css4[6] = '_';                                      // valid: `css4` is modifiable
    for(const auto& ch : css4) {
        if (ch == '\0') {
            break;                                      // stop at the first '\0'
        }
        cout << ch;
    }

    cout << endl;

    char css5[50] = {};                                 // value inited
    strcpy(css5, ss3.c_str());                          // make sure to make a copy of the returned value of `c_str`

    for(const auto& ch : css5) {
        if (ch == '\0') {
            break;                                      // stop at the first '\0'
        }
        cout << ch;
    }

    cout << endl;

    vector<vector<int>> vecivec;
    cout << vecivec.size() << endl;

    /* List init. -> Direct init. */
    vector<string> vs = {5, "april211"};          // Note: the use of `=` is permitted!
    cout << "Size of `vs`: " << vs.size() << endl;
    for (const auto& vs_elem : vs) {
        cout << vs_elem << endl;
    }

    auto ss1_iter = ss1.begin();
    ss1_iter++;
    cout << *ss1_iter << endl;

    const vector<int> ivec_const = {42, 42, 42};
    // const int cst_i = 0;
    // ivec_const.push_back(cst_i);                             // illegal: can't push back elem to a const vec

    // const vector<int> ivec = {0, 1, 2};
    // ivec_const = ivec;                                       // illegal: top-level const
    // ivec_const = {0, 1, 2};                                  // illegal!

    auto ivec_const_cit = ivec_const.begin();                   // type: std::vector<int>::const_iterator
    // *ivec_const_cit = -1;                                    // illegal: low-level const
    // ivec_const[0] = -1;                                      // illegal too!
    cout << *ivec_const_cit << endl;

    return 0;
}