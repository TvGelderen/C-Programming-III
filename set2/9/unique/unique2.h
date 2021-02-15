#include "unique.ih"

template <class T>
Unique<T>::Unique(Unique<T> const &other)
{
    d_ptr = unique_ptr<T>(new T(*other.d_ptr));
}
