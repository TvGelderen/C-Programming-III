#include <iostream>
#include "counter/counter.h"

using namespace std;

int main()
{
    Counter<int> one;
    Counter<int> two;
    
    if (true)
        Counter<int> three;

    Counter<string> str;


    cout << "count<int>:  " << two.count() << '\n';
    cout << "actual<int>: " << two.actual() << '\n';
    cout << "count<string>: " << str.count() << '\n';
    cout << "actual<string>: " << str.actual() << '\n';

    cout << "global count (from str): " << str.globalcount() << '\n';      //global counts
    cout << "global actual (from str): " << str.globalactual() << '\n';
    cout << "global count (from two): " << two.globalcount() << '\n';      //should result in the same
    cout << "global actual (from two): " << two.globalactual() << '\n';
}
