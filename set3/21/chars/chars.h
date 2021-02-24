#ifndef INCLUDED_CHARS_
#define INCLUDED_CHARS_

#include <ostream>

template <char ch = ' ', char ...Params>  // default first char is a space
struct Chars
{
    template <char arg, char ...Args>
    friend std::ostream &operator<<(std::ostream &out,
                                    Chars<arg, Args ...> const &chars);
};

template <char ch, char ...Params>
inline std::ostream &operator<<(std::ostream &out,
                                    Chars<ch, Params ...> const &chars)
{
    out << ch;
    out << Chars<Params ...>();
    return out;
}

template <char ch>                        // specialized for the last char
struct Chars<ch>
{
    template <char arg>
    friend std::ostream &operator<<(std::ostream &out,
                                    Chars<arg> const &chars);
};

template <char ch>
inline std::ostream &operator<<(std::ostream &out, Chars<ch> const &chars)
{
    out << ch;
    return out;
}

#endif
