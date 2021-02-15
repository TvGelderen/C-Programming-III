#ifndef _INCLUDED_COUNTER1_
#define _INCLUDED_COUNTER1_

template <typename Type>
Counter<Type>::Counter()
{
    ++s_count;                            //increase both counters!
    ++s_actual;                             
}

#endif