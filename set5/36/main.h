#include <concepts>

template <totally_ordered Lhs, totally_ordered Rhs>
auto compare(Lhs lhs, Rhs rhs);

template <totally_ordered Type>
class Compare;
