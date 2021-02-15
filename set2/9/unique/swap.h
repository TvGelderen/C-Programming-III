#include "unique.ih"

template <class T>
void Unique<T>::swap(Unique<T> &other)
{
    d_ptr.swap(other.d_ptr);
}
