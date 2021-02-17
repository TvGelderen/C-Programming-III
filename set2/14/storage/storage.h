#ifndef _INCLUDED_STORAGE_
#define _INCLUDED_STORAGE_

#include <vector>
#include <iterator>
#include <string>

//template <typename Data> 
class Storage
{
    std::vector<std::string *> d_storage;
    public:

            // the usual stuff goes here
            void push_back(std::string const &value); //to demonstrate. 
            class iterator;                         //definend + declared in iterator.h!

            Storage::iterator begin();              //iterator to first elem
            Storage::iterator end();                //iterator to last elem
};

#include "iterator.h"                               //contains the iterator implementation + declaration

inline Storage::iterator Storage::begin()
{
    return iterator(d_storage.begin());             //construct iterator pointing to begin of the internal vector
}

inline Storage::iterator Storage::end()
{
    return iterator(d_storage.end());               //construct iterator pointing to end of the internal vector
}
#endif
