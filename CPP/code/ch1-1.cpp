#include <iostream>
using namespace std;            // TODO learn more about namespaces


int main() {

    int val1 = 0, val2 = 0;
    int sum = 0;
    int prod = 0;

    cout << "Give me two numbers: " << endl;

    cin >> val1 >> val2;

    sum = val1 + val2;

    prod = val1 * val2;

    cout << "The sum of " << val1 << " and " << val2 << " is " << sum << endl;

    cout << "The product of " << val1 << " and " << val2 << " is " << prod << endl;

    cout << "val1: " << val1 << endl;

    cout << "val2: " << val2 << endl;

    cout << "sum: " << sum << endl;

    cout << "prod: " << prod << endl;

    cout << "Hello, World!" << endl;

    return 0;
}