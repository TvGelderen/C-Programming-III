#ifndef _INCLUDED_FORWARDER_
#define _INCLUDED_FORWARDER_

#include <utility>

template <typename Fun, typename ...Params>
void forwarder(Fun &&fun, Params &&...params)
{
    fun(std::forward<Params>(params)...);
}

#endif