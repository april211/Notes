#include <iostream>
#include <string>
#include "sales_data.h"
using namespace std;

/*
* 0-201-78345-X 3 20.00 0-201-78345-X 2 25.00
*/

int main() {

    Sales_data data1, data2;

    double price_per_book = 0.0;

    cin >> data1.bookNo >> data1.units_sold >> price_per_book;
    data1.revenue = data1.units_sold* price_per_book;

    cin >> data2.bookNo >> data2.units_sold >> price_per_book;
    data2.revenue = data2.units_sold* price_per_book;

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        cout << data1.bookNo << ' ' << totalCnt << ' ' << totalRevenue << ' ';

        if (totalCnt > 0) {                 // to avoid DbZ error 
            cout << totalRevenue / totalCnt << endl;
        } else {
            cout << "(no sales)" << endl;
        }

        return 0;
    } else {
        cerr << "Data must refer to the same ISBN" << endl;

        return -1;
    }
}