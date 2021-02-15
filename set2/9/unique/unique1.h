#include "unique.ih"

template <class T>
Unique<T>::Unique(T val)
{
    d_ptr = unique_ptr<T>(new T(val));
}
