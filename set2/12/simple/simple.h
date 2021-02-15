#ifndef _INCLUDED_SIMPLE_
#define _INCLUDED_SIMPLE_

#include "get.h"
#include "simple1.h"
#include "simple2.h"
#include <iostream>

template <class Type>
class Simple
{
    Type d_value = Type{};
    
    public:
        Simple();
        Simple(Type const &value);

        Type &get();
};

#endif