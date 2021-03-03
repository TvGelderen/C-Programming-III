#include "traits.h"

#include <iostream>

using namespace std;

template<typename Type>
Type * const makeConst(Type val)
{
    return new Type{ val };
}

int main()
{
    cout << Traits<int>::value << '\n'
         << Traits<int*>::value << '\n'
         << Traits<int&>::value << '\n'
         << Traits<int&&>::value << '\n';

    auto ptr = makeConstPtr(42);
    cout << "ptr value: " << *ptr << '\n';
}
