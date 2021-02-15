#include "unique.ih"

template <class T>
Unique<T>::Unique(Unique<T> &&tmp)
:
    d_ptr(move(tmp.d_ptr))
{}
