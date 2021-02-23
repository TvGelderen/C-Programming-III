#ifndef _INCLUDED_PUSH_BACK_
#define _INCLUDED_PUSH_BACK_

template <typename Data>
void Storage<Data>::push_back(Data const &&value)
{
    Data  *ptr = new Data(value);                 
    d_storage.push_back(ptr);                     //push the value to the internal vector
}

#endif

