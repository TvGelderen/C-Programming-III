#ifndef _INCLUDED_BASICMATH_H_
#define _INCLUDED_BASICMATH_H_

template <typename Type>
concept BasicMath =
    requires(Type value)
    {
        value + 1;
        value - 1;
        value * 1;
        value / 1;
        -value;
    };

#endif

//a concept that requires elementary math!