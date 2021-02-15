#include "unique.ih"

template <class T>
T &Unique<T>::get()
{
    return *d_ptr;
}
