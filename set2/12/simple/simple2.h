#include "simple.ih"

template <class Type>
Simple<Type>::Simple(Type val)
:
    d_type(val)
{
    cout << "standard Type constructor\n";
}
