#ifndef _INCLUDED_GET2_
#define _INCLUDED_GET2_

template <class T>
T const &Unique<T>::get() const
{
    return *d_ptr;
}

#endif