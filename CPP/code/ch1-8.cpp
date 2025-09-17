#include <iostream>
#include "sales_item.h"
using namespace std;


/*

"The records for each ISBN should be grouped together."

0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
0-201-70353-X 4 24.99
0-201-70353-X 5 24.99
0-201-70353-X 7 24.99
0-201-71394-X 1 54.99

*/


int main() {

    Sales_item last_con_item;

    cout << "Give me a series of transaction items (ends it with `Ctrl+D` on Linux): " << endl;

    if (cin >> last_con_item) {

        Sales_item temp;

        while (cin >> temp) {
            if (last_con_item.isbn() == temp.isbn()) {
                last_con_item += temp;
            } else {
                cout << "The report for the book " << last_con_item.isbn() << " is: " << last_con_item << endl;
                last_con_item = temp;
            }
        }

        cout << "The report for the book " << last_con_item.isbn() << " is: " << last_con_item << endl;

        return 0;

    }  else {

        cerr << "Invalid input / Hit EoF!" << endl;

        return -1;

    }
}