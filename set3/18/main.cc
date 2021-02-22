#include <iostream>

using namespace std;

template <size_t nr>
struct Bin
{
    enum
    {             
        value = (nr & 1) + 10 * Bin<(nr >> 1)>::value      //add last bit to result and shift 1 digit using x10
    };
};

template <>
struct Bin<0>
{
    enum
    { 
        value = 0                               //stop when 0 is reached
    };
};

int main()
{
    cout << Bin<5>::value  << '\n' <<
            Bin<13>::value  << '\n' <<
            Bin<9>::value  << '\n' <<
            Bin<27>::value << '\n';
}
        


