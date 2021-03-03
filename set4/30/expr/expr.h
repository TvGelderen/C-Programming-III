#ifndef INCLUDED_EXPR_
#define INCLUDED_EXPR_
#define tHDR_ template <typename LHS, typename RHS, \
                            template <typename> class Operation>

#include <iostream>
#include <vector>

tHDR_
class Expr
{
    template <typename Class>
    struct Trait;

    LHS const &d_lhs;
    RHS const &d_rhs;

    public:
        typedef typename Trait<LHS>::VType VType;
        typedef typename VType::value_type value_type;

        Expr(LHS const &lhs, RHS const &rhs);

        auto operator[](size_t idx) const;
        operator VType() const;
        size_t size() const;
};

tHDR_
inline Expr<LHS, RHS, Operation>::Expr(LHS const &lhs, RHS const &rhs)
:
    d_lhs(lhs),
    d_rhs(rhs)
{}

tHDR_
inline auto Expr<LHS, RHS, Operation>::operator[](size_t idx) const
{
    return Operation<value_type>{}(d_lhs[idx], d_rhs[idx]);
}

tHDR_
inline Expr<LHS, RHS, Operation>::operator VType() const
{
    VType ret;
    ret.reserve(d_lhs.size());

    for (size_t idx = 0; idx != d_lhs.size(); ++idx)
        new(&ret[idx]) value_type((*this)[idx]);

    return ret;
}

tHDR_
inline size_t Expr<LHS, RHS, Operation>::size() const
{
    return d_lhs.size();
}

tHDR_
template <typename Class>
struct Expr<LHS, RHS, Operation>::Trait
{
    typedef typename Class::VType VType;
};

tHDR_
template <typename Type>
struct Expr<LHS, RHS, Operation>::Trait<std::vector<Type>>
{
    typedef typename std::vector<Type> VType;
};

                                                // OVERLOADED OPERATORS
template <typename LHS, typename RHS>
auto operator+(LHS const &lhs, RHS const &rhs)
{
return Expr<LHS, RHS, std::plus> { lhs, rhs };
}

template <typename LHS, typename RHS>
auto operator-(LHS const &lhs, RHS const &rhs)
{
return Expr<LHS, RHS, std::minus> { lhs, rhs };
}

template <typename LHS, typename RHS>
auto operator*(LHS const &lhs, RHS const &rhs)
{
return Expr<LHS, RHS, std::multiplies> { lhs, rhs };
}

template <typename LHS, typename RHS>
auto operator/(LHS const &lhs, RHS const &rhs)
{
return Expr<LHS, RHS, std::divides> { lhs, rhs };
}

#undef tHDR_
#endif
