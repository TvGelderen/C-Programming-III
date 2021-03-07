#ifndef _INCLUDED_SUB_
#define _INCLUDED_SUB_

#include "iostream"

template<typename Lhs, typename Rhs>
struct Sub
{
    static void operation(Lhs &lhs, Rhs &rhs);
};

template<typename Lhs, typename Rhs>
void Sub<Lhs, Rhs>::operation(Lhs &lhs, Rhs &rhs)
{
    std::cout << lhs - rhs << ' ';
};

#endif
