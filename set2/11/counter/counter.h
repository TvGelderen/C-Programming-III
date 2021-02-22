#ifndef INCLUDED_COUNTER_
#define INCLUDED_COUNTER_

//#include <cstddef>

#include "../globalcounter/globalcounter.h"
template <class T>
class Counter : public GlobalCounter
{
    static size_t s_count;
    static size_t s_actual;
    
    public:
        Counter();
        ~Counter();

        size_t count() const;
        size_t actual() const;
};

template <class T>
size_t Counter<T>::s_count = 0;
template <class T>
size_t Counter<T>::s_actual = 0;

template <class T>
inline Counter<T>::Counter()
{
    ++s_count;
    ++s_actual;
}

template <class T>
inline Counter<T>::~Counter()
{
    --s_actual;
}

template <class T>
inline size_t Counter<T>::count() const
{
    return s_count;
}

template <class T>
inline size_t Counter<T>::actual() const
{
    return s_actual;
}

#endif
