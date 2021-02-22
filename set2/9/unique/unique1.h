#ifndef INCLUDED_UNIQUE1_
#define INCLUDED_UNIQUE1_

template <class T>
Unique<T>::Unique(T val)
{
    d_ptr = std::make_unique<T>(val);
}

#endif