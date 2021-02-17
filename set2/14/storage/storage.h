#ifndef _INCLUDED_STORAGE_
#define _INCLUDED_STORAGE_

#include <vector>
#include <iterator>
#include <string>

template <typename Data> 
class Storage
{
    std::vector<Data *> d_storage;
    public:
            ~Storage();                         //to prevent mem leak
            void push_back(Data const &&value); //to demonstrate. 
            
            class iterator;                         //definend + declared in iterator.h!
            typedef std::reverse_iterator<iterator> reverse_iterator;

            Storage<Data>::iterator begin();              //iterator to first elem
            Storage<Data>::iterator end();                //iterator to last elem
            std::reverse_iterator<iterator> rbegin();
            std::reverse_iterator<iterator> rend();
};

#include "iterator.h"                               //contains the iterator implementation + declaration

template <typename Data> 
inline Storage<Data>::iterator Storage<Data>::begin()
{
    return iterator(d_storage.begin());             //construct iterator pointing to begin of the internal vector
}

template <typename Data> 
inline Storage<Data>::iterator Storage<Data>::end()
{
    return iterator(d_storage.end());               //construct iterator pointing to end of the internal vector
}

template <typename Data> 
inline Storage<Data>::reverse_iterator Storage<Data>::rbegin()
{
    return reverse_iterator(end());                             //note begin = end!
}

template <typename Data> 
inline Storage<Data>::reverse_iterator Storage<Data>::rend()
{
    return reverse_iterator(begin());                           //end = begin!!
}
#endif
