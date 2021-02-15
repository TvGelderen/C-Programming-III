#include "unique.ih"

template <class T>
Unique<T> &Unique<T>::operator=(Unique<T> const &other)
{
    Unique<T> tmp{ other };
    swap(tmp);
    return *this;
}
