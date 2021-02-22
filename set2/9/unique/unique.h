#ifndef INCLUDED_UNIQUE_
#define INCLUDED_UNIQUE_

#include <memory>

template <class T>
class Unique
{
    std::unique_ptr<T> d_ptr;

    public:
        Unique(T val);
        Unique(Unique<T> const &other);
        Unique(Unique<T> &&tmp);

        Unique<T> &operator=(Unique<T> const &other);
        Unique<T> &operator=(Unique<T> &&tmp);

        void swap(Unique<T> &other);

        T &get();
        T const &get() const;
};

#include "unique.h"
#include "unique1.h"
#include "unique2.h"
#include "unique3.h"
#include "operatorassign1.h"
#include "operatorassign2.h"
#include "swap.h"
#include "get1.h"
#include "get2.h"       // This will include all required function definitions

#endif
