#include <iostream>

using namespace std;

template <char ...chars>
struct Chars
{};                    

template <char ch>
struct OneChar
{};

template< typename lhs, typename rhs >
struct Merge;                                   //'basis' template of Merge

template <char ... lhs, char ... rhs >          //specialization Chars & Chars
struct Merge< Chars< lhs ... >, Chars< rhs ... > >
{ 
    typedef Chars< lhs ..., rhs ... > CP;       //define the type, merging lhs and rhs
};

template <char ... lhs, char rhs >             //specialization Chars & OneChar
struct Merge< Chars< lhs ... >, OneChar<rhs> >
{ 
    typedef Chars< lhs ..., rhs> CP;            
};

template<char ...chars>
ostream& operator<<(ostream& out, Chars<chars...> insert)
{
    return (out << ... << chars);               //Simple insert in ostream for this exercise!
}

int main()
{

    cout << 
        Merge<                                 //indeed shows 123456
            Chars<'1', '2', '3'>, 
            Merge<Chars<'4', '5'>, OneChar<'6'>>::CP
        >::CP{} << '\n';                        
    
}
        