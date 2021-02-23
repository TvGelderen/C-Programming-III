#ifndef _INCLUDED_STORAGE_
#define _INCLUDED_STORAGE_

#include <vector>

template <typename Data>
class Storage
{
    std::vector<Data *> d_storage;
    public:
            ~Storage();                         //to prevent mem leak

            void push_back(Data const &&value); //to demonstrate.

            class iterator;            //definend + declared in iterator.h

            Storage<Data>::iterator begin();         //iterator to first elem
            Storage<Data>::iterator end();           //iterator to last elem
};

#include "push_back.h"          // push_back function
#include "destructor.h"         // destructor
#include "iterator/iterator.h"  // contains the iterator impl + decl

template <typename Data>
inline Storage<Data>::iterator Storage<Data>::begin()
{            
    return iterator(d_storage.begin()); //iterator pointing to begin of vector
}

template <typename Data>
inline Storage<Data>::iterator Storage<Data>::end()
{            
    return iterator(d_storage.end());   //iterator pointing to end of vector
}

#endif
