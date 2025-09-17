#include <iostream>
#include "sales_item.h"
using namespace std;


/*

0-201-78345-X 3 20.00
0-201-78345-X 2 25.00

0-201-70353-X 4 24.99
0-201-70353-X 5 24.99
0-201-70353-X 7 24.99

0-201-71394-X 1 54.99

*/


int main() {

    // Sales_item item;

    // int cnt = 1;

    // cout << "Give me a series of transaction items: " << endl;

    // while (cin >> item) {
    //     cout << "Item " << cnt << " : " << item << endl;
    //     ++cnt;
    // }

    // // Note: `Ctrl+D` terminates the program here. Please comment out the code above.
    // // https://stackoverflow.com/questions/5146344/problem-with-consecutive-cins

    // Sales_item item1, item2;

    // cout << "Give me two transaction items that have the same ISBN: " << endl;

    // cin >> item1 >> item2;

    // if (item1.isbn() == item2.isbn()) {

    //     cout << "The sum of two items: " << item1 + item2 << endl;

    //     return 0;

    // } else {

    //     cerr << "Data must refer to same ISBN" << endl;

    //     return -1;
    // }

    // // Note: `Ctrl+D` terminates the program here. Please comment out the code above.
    // // https://stackoverflow.com/questions/5146344/problem-with-consecutive-cins

    cout << "Give me a series of transaction items that have the same ISBN (ends it with `Ctrl+D` on Linux): " << endl;

    Sales_item item_sum, temp;

    if (cin >> item_sum) {                                               // don't print the default value when come across invalid init input

        while (cin >> temp) {
            if (temp.isbn() == item_sum.isbn()){
                item_sum += temp;
            } else {
                cerr << "Data must refer to same ISBN" << endl;
                return -1;
            }
        }

        cout << "The sum of the item series: " << item_sum << endl;

        return 0;

    } else {

        cerr << "Invalid input / Hit EoF!" << endl;

        return -1;

    }
}