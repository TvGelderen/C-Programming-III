#ifndef _INCLUDED_PUSHBACK_
#define _INCLUDED_PUSHBACK_

template <typename Data>
void Storage<Data>::push_back(Data const &&value)
{
    Data  *ptr = new Data(value);
    d_storage.push_back(ptr);
}

#endif