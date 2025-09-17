#include <iostream>
using namespace std;


/*
* try out these two inputs & compare the way they output the results:
* 
* 1 1 1 1 2 2 3 (The output is delayed until the finish of the full input.)
* 
* ---
* 
* 1
* 1
* 1
* 1
* 2
* 2
* 3 (It gives the output instantly.)
*/


int main() {

    cout << "Give me a series of numbers (ends it with `Ctrl+D` on Linux): " << endl;

    int last_con_val = 0;

    if (cin >> last_con_val) {                                                        // make sure that we have data to process

        int cnt = 1, temp = -1;

        while (cin >> temp) {
            if (temp == last_con_val) {
                ++cnt;
            } else {
                cout << last_con_val << " appears " << cnt << " times." << endl;     // Note: inside & outsize the loop!
                last_con_val = temp;                                                 // prepare for the next item
                cnt = 1;                                                             // at least once
            }
        }

        cout << last_con_val << " appears " << cnt << " times." << endl;             // Note: inside & outsize the loop!

        return 0;

    } else {

        cerr << "Invalid input / Hit EoF!" << endl;

        return -1;

    }
}