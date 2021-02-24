#ifndef INCLUDED_CHARS_
#define INCLUDED_CHARS_

#include <vector>
#include <ostream>

template <char ch = ' ', char ...Params>  // default first char is a space
struct Chars
{
    std::vector<char> d_chars;

    Chars();

    template <char ...Args>
    friend std::ostream &operator<<(std::ostream &out, Chars<Args ...> const &chars);
};

template <char ch, char ...Params>
inline Chars<ch, Params ...>::Chars()
{
    d_chars.push_back(ch);      // add the char to the vector
    Chars<Params ...> chars;    // create a Chars object with the other chars
                        // append the other chars to the current vector
    d_chars.insert(d_chars.end(), chars.d_chars.begin(), chars.d_chars.end());
}

template <char ...Params>
inline std::ostream &operator<<(std::ostream &out, Chars<Params ...> const &chars)
{
    for (size_t idx = 0; idx != chars.d_chars.size(); ++idx)
        out << chars.d_chars[idx];

    return out;
}

template <char ch>              // specialized for the last char
struct Chars<ch>
{
    std::vector<char> d_chars;

    Chars();
};

template <char ch>
inline Chars<ch>::Chars()
{
    d_chars.push_back(ch);
}



#endif
