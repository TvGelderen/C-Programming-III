#ifndef _INCLUDED_COUNTER2_
#define _INCLUDED_COUNTER2_

template <typename Type>
Counter<Type>::Counter(Type const &value)
:
        d_value(value)
{
    ++s_count;                            //increase both counters!
    ++s_actual;                                     
}

#endif