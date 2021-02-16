#ifndef INCLUDED_SIMPLE_
#define INCLUDED_SIMPLE_

template <class Type>
class Simple
{
    Type d_type;

    public:
        Simple();
        Simple(Type val);

        Type &get();
};

#include "simple1.h"
#include "simple2.h"
#include "get.h"
                        // include the partial specialization for pointers
#include "../simple_ptr/simple.h"

#endif
