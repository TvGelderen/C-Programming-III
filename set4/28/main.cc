#include "traits.h"

#include <iostream>

using namespace std;

template<typename Type>
void checkType(Type p)
{
    cout << Traits<Type>::value << '\n';
}

int main()
{   
    cout << Traits<int>::value << '\n'
        << Traits<int*>::value << '\n'
        << Traits<int&>::value << '\n'
        << Traits<int&&>::value << '\n';

    int basic = 5;
    int &ref = basic;
    int *pointer = &basic;
    int &&rref = std::move(basic);

    checkType(basic);
    checkType(ref);
    checkType(pointer);
    checkType(std::move(rref));
}