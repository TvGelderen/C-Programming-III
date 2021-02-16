#ifndef _INCLUDED_COUNTER_
#define _INCLUDED_COUNTER_

#include <iostream>

template <typename Type>
class Counter
{
    static size_t s_count;
    static size_t s_actual;
    Type d_value = Type{};

    public:
            Counter();
            Counter(Type const &value);
            ~Counter(); 

            void show();
};

template <typename Type>
size_t Counter<Type>::s_count = 0;                //declaration != definition
template <typename Type>
size_t Counter<Type>::s_actual = 0;                //declaration != definition

#endif
