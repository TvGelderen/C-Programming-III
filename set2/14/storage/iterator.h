#ifndef _INCLUDED_ITERATOR_
#define _INCLUDED_ITERATOR_

template <typename Data>
class Storage<Data>::iterator: public std::iterator<std::random_access_iterator_tag, Data>
{
    friend class Storage<Data>;          
    std::vector<Data *>::iterator d_current; 
    iterator(std::vector<Data *>::iterator current):
        d_current(current)
    {}  
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

        Data &operator*();
        Data *operator->();
        iterator &operator=(iterator const &other) = default;   //we merely access the data
        iterator(iterator const &other) = default;              //so these can be default
};

template <typename Data> 
inline Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
    ++d_current;
    return *this;
}

template <typename Data> 
inline Storage<Data>::iterator &Storage<Data>::iterator::operator--()
{
    --d_current;
    return *this;
}

template <typename Data> 
inline Storage<Data>::iterator Storage<Data>::iterator::operator++(int)
{
    return iterator(d_current++);
}

template <typename Data> 
inline Storage<Data>::iterator Storage<Data>::iterator::operator--(int)
{
    return iterator(d_current--);
}

template <typename Data> 
inline bool Storage<Data>::iterator::operator==(iterator const &rhv)  const
{
    return d_current == rhv.d_current;
}

template <typename Data> 
inline bool Storage<Data>::iterator::operator!=(iterator const &rhv) const
{
    return not (d_current == rhv.d_current);
}

template <typename Data> 
inline bool Storage<Data>::iterator::operator<(iterator const &rhv) const
{
    return d_current < rhv.d_current;
}

template <typename Data> 
inline int Storage<Data>::iterator::operator-(iterator const &rhv) const
{
    return d_current - rhv.d_current;
}

template <typename Data> 
inline Storage<Data>::iterator Storage<Data>::iterator::operator+(int step) const
{
    return iterator{ d_current + step };
}

template <typename Data> 
inline Storage<Data>::iterator Storage<Data>::iterator::operator-(int step) const
{
    return iterator{ d_current - step };
}

template <typename Data> 
inline Storage<Data>::iterator &Storage<Data>::iterator::operator+=(int step) 
{
    d_current += step;
    return *this;
}

template <typename Data> 
inline Storage<Data>::iterator &Storage<Data>::iterator::operator-=(int step) 
{
    d_current -= step;
    return *this;
}

template <typename Data> 
inline Data &Storage<Data>::iterator::operator*()
{
    return **d_current;
}

template <typename Data> 
inline Data *Storage<Data>::iterator::operator->()
{
    return *d_current;
}

#endif