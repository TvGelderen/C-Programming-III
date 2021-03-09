#include <iostream>

#include "tuplemod.h"

using namespace std;

int main()
{
    tuple<int, double> t1{ 1, 12.5 };

    TupleMod< tuple<int, double> > tmod(t1);

    auto t2 = t1 + t1;
    cout << tuple_size< decltype(t2) >::value << '\n';  // shows 4

    auto t3 = tmod.add(12);
    cout << tuple_size< decltype(t3) >::value << '\n';  // shows 3

    tuple<int, double, string> t4{ 1, 12.5, "hello world" };

    auto t5 = t1 + t4;
    cout << tuple_size< decltype(t5) >::value << '\n';  // shows 5
}
