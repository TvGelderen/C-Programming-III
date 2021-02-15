#ifndef _INCLUDED_COUNTER3_
#define _INCLUDED_COUNTER3_

template <typename Type>
Counter<Type>::~Counter()
{
    std::cout << "destructor called" << '\n';
    --s_actual;                 //only decrease actual, so count keeps track of total!
}
 
 #endif