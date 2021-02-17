#ifndef _INCLUDED_ITERATOR_
#define _INCLUDED_ITERATOR_

#include <string>
//template <typename Data>
class Storage::iterator: public std::iterator<std::random_access_iterator_tag, std::string>
{
    friend class Storage;
    iterator(std::vector<std::string *>::iterator current):
        d_current(current)
    {}            
    std::vector<std::string *>::iterator d_current; 

    public:
        iterator &operator++();
        iterator &operator--();
        iterator operator++(int);
        iterator operator--(int);

        bool operator==(iterator const &rhv) const;
        bool operator!=(iterator const &rhv) const;
        bool operator<(iterator const &rhv) const;
        int operator-(iterator const &rhv) const;
        iterator operator+(int step) const;
        iterator operator-(int step) const;
        iterator &operator+=(int step);
        iterator &operator-=(int step);

        std::string &operator*();
        std::string *operator->();
        iterator &operator=(iterator const &other) = default;   //we merely access the data
        iterator(iterator const &other) = default;              //so these can be default
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

inline Storage::iterator Storage::iterator::operator++(int)
{
    return iterator(d_current++);
}

inline Storage::iterator Storage::iterator::operator--(int)
{
    return iterator(d_current--);
}

inline bool Storage::iterator::operator==(iterator const &rhv)  const
{
    return d_current == rhv.d_current;
}

inline bool Storage::iterator::operator!=(iterator const &rhv) const
{
    return not (d_current == rhv.d_current);
}

inline bool Storage::iterator::operator<(iterator const &rhv) const
{
    return d_current < rhv.d_current;
}

inline int Storage::iterator::operator-(iterator const &rhv) const
{
    return d_current - rhv.d_current;
}

inline Storage::iterator Storage::iterator::operator+(int step) const
{
    return iterator{ d_current + step };
}

inline Storage::iterator Storage::iterator::operator-(int step) const
{
    return iterator{ d_current - step };
}

inline Storage::iterator &Storage::iterator::operator+=(int step) 
{
    d_current += step;
    return *this;
}

inline Storage::iterator &Storage::iterator::operator-=(int step) 
{
    d_current -= step;
    return *this;
}

inline std::string &Storage::iterator::operator*()
{
    return **d_current;
}

inline std::string *Storage::iterator::operator->()
{
    return *d_current;
}

#endif