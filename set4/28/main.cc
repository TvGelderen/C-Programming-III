#include "traits.h"

#include <iostream>

using namespace std;

template<typename Type>
int const * makeConstPtr(Type val)
{
            // pointer case
    if constexpr(Traits<Type>::value == 2)
        return new int( *val );
            // r-value reference case
    else if constexpr(Traits<Type>::value == 4)
        return new int( std::move(val) );
            // plain type, reference case
    else
        return new int ( val );
}

int main()
{

    int basic = 5;
    int *pointer = &basic;
    int &ref = basic;
    int &&rref = std::move(basic);

    cout << "Plain " << Traits<decltype(basic)>::value << '\n'
         << "Pointer " << Traits<decltype(pointer)>::value << '\n'
         << "Reference " << Traits<decltype(ref)>::value << '\n'
         << "R Reference " << Traits<decltype(rref)>::value << '\n';

    auto ptr = makeConstPtr(basic);
    cout << "ptr value: " << *ptr << '\n';
    delete ptr;
}
