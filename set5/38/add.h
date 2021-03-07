#ifndef _INCLUDED_ADD_
#define _INCLUDED_ADD_

#include <iostream>

template<typename Lhs, typename Rhs>
struct Add
{
    static void operation(Lhs &lhs, Rhs &rhs);
};

template<typename Lhs, typename Rhs>
void Add<Lhs, Rhs>::operation(Lhs &lhs, Rhs &rhs)
{
    std::cout << lhs + rhs << ' ';
};

#endif
