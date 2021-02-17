#ifndef _INCLUDED_STORAGE_
#define _INCLUDED_STORAGE_


#include <vector>
#include <iterator>
#include "iterator/iterator.ih" 

template <typename Data>
class Storage
{
    std::vector<Data *> d_storage;

    public:
            // the usual stuff goes here
            void push_back(Data const &value);

            class iterator: public std::iterator<std::random_access_iterator_tag, Data>
            {
                friend class Storage;
                
                public:
                    iterator &operator++()
                    iterator &operator--()
                    iterator operator++(int)
                    iterator operator--(int)

                    bool operator==(iterator const &rhv) const
                    bool operator!=(iterator const &rhv) const
                    bool operator<(iterator const &rhv) const
                    int operator-(iterator const &rhv) const
                    iterator operator+(int step) const;
                    iterator operator-(int step) const;

                    Data &operator*();
                    Data *operator->();
                    iterator &operator=(iterator const &other) = default;   //we merely access the data
                    iterator(iterator const &other) = default;              //so these can be default
            };


            Storage::iterator begin();              //iterator to first elem
            Storage::iterator end();                //iterator to last elem
};


inline Storage::iterator &Storage::iterator::operator++()
{
    ++d_current;
    return *this;
}

inline Storage::iterator &Storage::iterator::operator--()
{
    --d_current;
    return *this;
}

inline Storage::iterator Storage::iterator::operator--(int)
{
    return iterator(d_current++);
}

inline Storage::iterator Storage::iterator::operator--(int)
{
    return iterator(d_current--);
}

inline bool operator==(Storage::iterator const &lhs, Storage::iterator const &rhs) 
{
    return lhs.d_current == rhs.d_current;
}

inline bool operator!=(Storage::iterator const &lhs, Storage::iterator const &rhs) 
{
    return not (lhs.d_current == rhs.d_current);
}

inline bool operator<(Storage::iterator const &lhs, Storage::iterator const &rhs) 
{
    return lhs.d_current < rhs.d_current;
}

inline bool operator-(Storage::iterator const &lhs, Storage::iterator const &rhs) 
{
    return lhs.d_current - rhs.d_current;
}

iterator operator+(Storage::iterator const &lhs, int step) const
{
    Storage::iterator ret{ lhs };
    ret.d_current += step;
    return ret;
}

iterator operator-(Storage::iterator const &lhs, int step) const;
{
    Storage::iterator ret{ lhs };
    ret.d_current -= step;
    return ret;
}

inline Data &Storage::iterator::operator*()
{
    return **d_current;
}

inline Data *Storage::iterator::operator->()
{
    return *d_current;
}

iterator &operator=(iterator const &other) = default;   //we merely access the data
iterator(iterator const &other) = default;              //so these can be default

#endif
