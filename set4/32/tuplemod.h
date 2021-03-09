#ifndef INCLUDED_EXPR_
#define INCLUDED_EXPR_

#include <tuple>

template <typename Tuple>
class TupleMod
{
    Tuple const &d_tuple;       // the available tuple

    public:
        TupleMod(Tuple const &tuple);

        template <typename ...AddParams>    // returns new tuple to which
        auto add(AddParams &&...addParams); // AddParams were added
};

template <typename Tuple>
inline TupleMod<Tuple>::TupleMod(Tuple const &tuple)
:
    d_tuple(tuple)
{}

template <typename Tuple>
template <typename ...AddParams>
inline auto TupleMod<Tuple>::add(AddParams &&...addParams)
{
    return std::tuple_cat(d_tuple,
            std::tuple<AddParams ...>(std::forward<AddParams>(addParams)...));
}

template <typename ...Lhs, typename ...Rhs>
auto operator+(std::tuple<Lhs ...> const &lhs, std::tuple<Rhs ...> const &rhs)
{
    return std::tuple_cat(lhs, rhs);
}

#endif
