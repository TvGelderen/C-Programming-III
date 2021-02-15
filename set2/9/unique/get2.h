#include "unique.ih"

template <class T>
T const &Unique<T>::get() const
{
    return *d_ptr;
}
