#ifndef _INCLUDED_STORAGE_
#define _INCLUDED_STORAGE_


#include <vector>

template <typename Data>
class Storage
{
    public:
            std::vector<Data *> d_storage;
            void push_back(Data const &value);
            // the usual stuff goes here

};

#include "push_back.h" 

#endif

