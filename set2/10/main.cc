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
}
