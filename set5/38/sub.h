#ifndef _INCLUDED_SUB_
#define _INCLUDED_SUB_

#include "iostream"

template<typename LType, typename RType>
struct Sub
{
    static void operation(LType &lhs, RType &rhs)
    {
        std::cout << lhs - rhs << ' ';
    };   
};

#endif