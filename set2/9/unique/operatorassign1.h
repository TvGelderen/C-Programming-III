#ifndef _INCLUDED_OP_ASSIGN1_
#define _INCLUDED_OP_ASSIGN1_

template <class T>
Unique<T> &Unique<T>::operator=(Unique<T> const &other)
{
    Unique<T> tmp{ other };
    swap(tmp);
    return *this;
}

#endif