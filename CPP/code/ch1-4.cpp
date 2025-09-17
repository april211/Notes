#include <iostream>
using namespace std;


int main() {

    int sum = 0, value = 0;

    cout << "Give me a series of numbers (ends it with `Ctrl+D` on Linux): " << endl;

    while (cin >> value) {       // tests `cin`: EoF or an invalid input (like a `char`)
        sum += value;
    }

    cout << "Sum is: " << sum << endl;

    return 0;
}