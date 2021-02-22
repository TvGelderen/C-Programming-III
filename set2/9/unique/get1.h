#ifndef _INCLUDED_GET1_
#define _INCLUDED_GET1_

template <class T>
T &Unique<T>::get()
{
    return *d_ptr;
}

#endif