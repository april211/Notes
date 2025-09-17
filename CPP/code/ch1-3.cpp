#include <iostream>
using namespace std;


int main() {

    int sum = 0;

    for (int i = 1; i <= 10; ++i) {
        sum += i;
    }

    cout << "Sum of 1 to 10 (inclusive): " << sum << endl;

    sum = 0;

    for (int i = -100; i <= 100; ++i) {
        sum += i;
    }

    cout << sum << endl;                // 0

    sum = 0;

    for (int i = 50; i <= 100; ++i) {
        sum += i;
    }

    cout << "Sum of 50 to 100 (inclusive): " << sum << endl;

    for (int i = 10; i >= 0; --i) {
        cout << i << endl;
    }

    return 0;
}