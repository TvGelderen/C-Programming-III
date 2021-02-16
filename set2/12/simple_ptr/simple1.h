#include "simple.ih"

template <class Type>
Simple<Type *>::Simple(Type *val)
:
    d_type(val)
{
    cout << "specialized Type ptr constructor\n";
}
