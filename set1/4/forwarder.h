#include <utility>

template <typename Fun, typename ...Params>
void forwarder(Fun &&fun, Params &&...params)
{
    fun(std::forward<Params>(params)...);
}