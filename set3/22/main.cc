#include <iostream>

#include "convert/convert.h"

using namespace std;

int main()
{
    cout << Convert<57005, 8>::CP{} << '\n';    // displays '157255'
    cout << Convert<57005, 16>::CP{} << '\n';   // displays 'dead'
    cout << Convert<57005, 32>::CP{} << '\n';   // displays '1nld'
    cout << Convert<0, 32>::CP{} << '\n';       // displays '0'
}