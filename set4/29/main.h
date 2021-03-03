#ifndef _INCLUDED_MAIN_
#define _INCLUDED_MAIN_

template <typename Type>
struct Plus
{
    Type operator()(Type const &lhs, Type const &rhs);
};

template <typename Type>
inline Type Plus<type>::operator()(Type const &lhs, Type const &rhs)
{
    return lhs + rhs;
}

template <typename LHS, typename RHS, template <typename> class Operation>
class Expr
{};

template <typename LHS, typename RHS>
auto operator+(LHS const &lhs, RHS const &rhs)
{
    return Expr<LHS, RHS, Plus> { lhs, rhs };
}

#endif
