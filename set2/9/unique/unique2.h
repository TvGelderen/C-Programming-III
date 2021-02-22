#ifndef INCLUDED_UNIQUE2_
#define INCLUDED_UNIQUE2_

template <class T>
Unique<T>::Unique(Unique<T> const &other)
{
    d_ptr = std::make_unique<T>(*other.d_ptr);
}

#endif