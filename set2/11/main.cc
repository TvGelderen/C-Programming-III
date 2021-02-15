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

    cout << "count:  " << str.count() << '\n';
    cout << "actual: " << str.actual() << '\n';
}
