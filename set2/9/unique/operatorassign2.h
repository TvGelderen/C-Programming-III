#include "unique.ih"

template <class T>
Unique<T> &Unique<T>::operator=(Unique<T> &&tmp)
{
    swap(tmp);
    return *this;
}
