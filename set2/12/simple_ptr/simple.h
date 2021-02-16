#ifndef INCLUDED_SIMPLE_PTR_
#define INCLUDED_SIMPLE_PTR_

template <class Type>
class Simple<Type *>
{
    Type *d_type;

    public:
        Simple(Type *val);

        Type &get();
};

#include "simple1.h"
#include "get.h"

#endif
