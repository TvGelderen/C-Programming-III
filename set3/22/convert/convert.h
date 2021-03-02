#ifndef INCLUDED_CONVERT_
#define INCLUDED_CONVERT_

#include "./display.h"

template <unsigned int nr, unsigned int radix>
struct Convert {
    typedef typename Display<true, nr, radix>::CP CP;
};

#endif