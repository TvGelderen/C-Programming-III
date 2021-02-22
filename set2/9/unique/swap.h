#ifndef _INCLUDED_SWAP_
#define _INCLUDED_SWAP_

template <class T>
void Unique<T>::swap(Unique<T> &other)
{
    d_ptr.swap(other.d_ptr);
}

#endif