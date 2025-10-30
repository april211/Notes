#include <iostream>
using namespace std;


// extern double pi = 3.14;                // warning: ‘pi’ initialized and declared ‘extern’ (`extern` has been overridden)

int main() {

    unsigned u = 10u, u2 = 42u;

    cout << u2 - u << endl;         // V
    cout << u - u2 << endl;         // X

    int i = 10, i2 = 42;
    cout << i2 - i << endl;         // V
    cout << i - i2 << endl;         // V

    cout << i - u << endl;          // V
    cout << u - i << endl;          // V

    // technically speaking, the value of a decimal literal is never a negative number.
    int a = 0 - 42;
    // int a = -42;
    cout << a << endl;

    double nd = 1.87;
    cout << nd + i << endl;         // OK: double

    int month = 9;
    int day = 07;
    // int day = 0x7;

    cout << month + day << endl;            // decimal

    cout << 0xFA << endl;                   // decimal

    cout << oct << 07 << endl;              // octal

    cout << hex << 0xFA << endl;            // hex

    cout << "Who goes with F\145rgus?\012" << endl;         // Note: a newline (\n) appended.

    float f = 1024.0f;
    // float f = 1024f;                     // ERROR!
    cout << f << endl;

    cout << "\062\115\012";                 // "2M\n" in oct format

    cout << "\x32\x4D\x0A";                 // "2M\n" in hex format

    cout << "\x32\x09\x4D\x0A";             // "2\tM\n" in hex format

    // long double ld = 3.1415926536;
    // int bd{ld}, cd = {ld};                  // warning: narrowing conversion ... 

    // cout << pi << endl;

    // int _ = 0;

    // cout << _ << endl;

    // double Double = 0.01;

    // extern int ext_i;
    // cout << ext_i << endl;           // trigger a complilation error by using an undefined ext var

    // cout << Double << endl;

    // i = 100;
    // int sum = 0;
    // for (int i = 0; i != 10; ++i) 
    //     sum += i;
    // cout << dec << i << " " << sum << endl;

    return 0;
}