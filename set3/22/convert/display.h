#ifndef INCLUDED_DISPLAY_
#define INCLUDED_DISPLAY_

#include "../merge/merge.h"

                    // general case
template <bool displayed, unsigned int nr, unsigned int radix> 
struct Display
{
    static constexpr unsigned int digit = nr % radix;
    static constexpr char digitChar = digit < 10 ?
        '0' + digit : 'a' + (digit - 10);
    
    typedef typename Merge<
        typename Display<false, nr / radix, radix>::CP,
        OneChar<digitChar>
    >::CP CP;
};
                    // base case, display zero
template <unsigned int radix>
struct Display<true, 0, radix>
{
    typedef Chars<'0'> CP;
};
                    // base case, display nothing
template <unsigned int radix>
struct Display<false, 0, radix>
{
    typedef Chars<> CP;
};

#endif
