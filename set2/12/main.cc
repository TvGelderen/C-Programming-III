#include <iostream>
#include "simple/simple.h"

using namespace std;

int main()
{
    Simple<int> sim1;

    cout << sim1.get() << '\n';

    int val = 12;

    Simple<int *> sim2{ &val };

    cout << sim2.get() << '\n';
}
