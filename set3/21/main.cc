#include <iostream>

using namespace std;

template <char ...chars>
struct Chars
{};

template<char ...chars>
ostream& operator<<(ostream& out, Chars<chars ...> &&insert)
{
    return (out << ... << chars);      // insert the template parameters
}

int main()
{
    cout << Chars<'h', 'e', 'l', 'l', 'o'>() << '\n' <<
            Chars<'m', 'e', 't', 'a'>() <<
            Chars<>() << '\n';
}
