#ifndef INCLUDED_UNIQUE3_
#define INCLUDED_UNIQUE3_

template <class T>
Unique<T>::Unique(Unique<T> &&tmp)
:
    d_ptr(move(tmp.d_ptr))
{}

#endif