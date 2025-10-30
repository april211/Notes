#ifndef SALES_DATA_H            // succeed at the first time
#define SALES_DATA_H
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};                              // Note: semicolon here! (expected ‘;’ after struct definition)
#endif                          // SALES_DATA_H