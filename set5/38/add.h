#ifndef _INCLUDED_ADD_
#define _INCLUDED_ADD_

#include <iostream>

template<typename LType, typename RType>
struct Add
{
    static void operation(LType &lhs, RType &rhs)
    {
        std::cout << lhs + rhs << ' ';
    };   
};

#endif