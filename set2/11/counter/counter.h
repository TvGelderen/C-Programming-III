#ifndef INCLUDED_COUNTER_
#define INCLUDED_COUNTER_

#include <cstddef>

template <class T>
class Counter
{
    public:
        Counter();
        ~Counter();

        size_t count() const;
        size_t actual() const;

        static size_t s_count;
        static size_t s_actual;
};

template <>
size_t Counter<void>::s_count = 0;
template <>
size_t Counter<void>::s_actual = 0;

template <class T>
inline Counter<T>::Counter()
{
    ++Counter<void>::s_count;
    ++Counter<void>::s_actual;
}

template <class T>
inline Counter<T>::~Counter()
{
    --Counter<void>::s_actual;
}

template <class T>
inline size_t Counter<T>::count() const
{
    return Counter<void>::s_count;
}

template <class T>
inline size_t Counter<T>::actual() const
{
    return Counter<void>::s_actual;
}

#endif
