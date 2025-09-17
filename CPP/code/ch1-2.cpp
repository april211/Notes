#include <iostream>
using namespace std;


int main() {

    int sum = 0;
    int i = 1;

    while (i <= 10) {
        sum += i;
        i++;                // don't forget about this!
    }

    cout << "Sum of 1 to 10 (inclusive): " << sum << endl;

    cout << (i <= 10) << endl;      // 0
    cout << (i == 11) << endl;      // 1

    sum = 0;
    i = 50;

    while (i <= 100) {
        sum += i;
        i++;                // don't forget about this!
    }

    cout << "Sum of 50 to 100 (inclusive): " << sum << endl;

    int j = 10;

    while (j >= 0) {
        cout << j << endl;
        --j;
    }

    int val1 = 0, val2 = 0;
    int k = 0;

    cout << "Give me two numbers: " << endl;
    cin >> val1 >> val2;

    // skip the validity check here

    // add it after finishing Section 1.4.4
    if (val1 > val2) {
        int temp = val2;
        val2 = val1;
        val1 = temp;
    }

    cout << "Range: " << endl;

    k = val1;                       // from the left bound
    while (k <= val2) {             // to the right bound
        cout << k << endl;
        ++k;
    }

    return 0;
}