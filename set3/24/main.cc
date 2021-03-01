#include <iostream>

using namespace std; 


template <size_t nr, char ...chars>
struct I2C
{
    static constexpr char const *s_ntbs = I2C<nr / 10, '0' + nr % 10, chars...>::s_ntbs;
};

template <>
struct I2C<0>
{
    static constexpr char s_ntbs[] = {'0', '\0'};
};

template <char ...chars>
struct I2C<0, chars...>
{
    static constexpr char s_ntbs[] = {chars..., '\0'};
};

int main()
{
    cout << I2C<123>::s_ntbs << '\n' <<     // shows 123
            I2C<0>::s_ntbs << '\n';         // shows 0

    string value{ I2C<15937>::s_ntbs };

    cout << value << '\n';                  // shows 15937
}
