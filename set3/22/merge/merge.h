#ifndef INCLUDED_MERGE_
#define INCLUDED_MERGE_

#include <iostream>

template <char ...chars>
struct Chars
{};

template <char ch>
struct OneChar
{};

template<typename lhs, typename rhs>
struct Merge;                            // 'base' template of Merge

template <char ...lhs, char ...rhs>      // specialization Chars & Chars
struct Merge<Chars<lhs ...>, Chars<rhs ...>>
{                                 // define the type, merging lhs and rhs
    typedef Chars<lhs ..., rhs ...> CP;
};

template <char ...lhs, char rhs>         // specialization Chars & OneChar
struct Merge<Chars<lhs ...>, OneChar<rhs>>
{
    typedef Chars<lhs ..., rhs> CP;
};

template<char ...chars>
std::ostream& operator<<(std::ostream& out, Chars<chars...> &&insert)
{                              // Simple insert in ostream for this exercise
    return (out << ... << chars);
}

#endif