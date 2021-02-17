#ifndef _INCLUDED_STORAGE_
#define _INCLUDED_STORAGE_

#include <vector>
#include <iterator>

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

              // contains the iterator implementation + declaration
#include "../iterator/iterator.h"

template <typename Data>
inline Storage<Data>::iterator Storage<Data>::begin()
{             // construct iterator pointing to begin of the internal vector
    return iterator(d_storage.begin());
}

template <typename Data>
inline Storage<Data>::iterator Storage<Data>::end()
{             // construct iterator pointing to end of the internal vector
    return iterator(d_storage.end());
}

#endif
