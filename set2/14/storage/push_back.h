#ifndef _INCLUDED_PUSHBACK_
#define _INCLUDED_PUSHBACK_

#include "storage.ih"

//template <typename Data>
void Storage::push_back(std::string const &value)
{
    string  *ptr = new string(value);
    d_storage.push_back(ptr);
}

#endif