#ifndef _INCLUDED_OP_ASSIGN2_
#define _INCLUDED_OP_ASSIGN2_

template <class T>
Unique<T> &Unique<T>::operator=(Unique<T> &&tmp)
{
    swap(tmp);
    return *this;
}

#endif