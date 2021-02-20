#include <iostream>

using namespace std;

template <size_t nr>
struct NrTrait
{
    enum
    { 
        value = nr,
        even = nr % 2 == 0,
        by3 = nr % 3 == 0,
        width = 1 + NrTrait<nr / 10>::width         // compute width recursively!
    };
};
template <>
struct NrTrait<0>
{
    enum { width = 0 };              //stopping specialization for recursion!
};

int main()
{
    cout << "value: " << NrTrait<1971962>::value << '\n' << 
            "even: " << NrTrait<1971962>::even << '\n' << 
            "by3: " << NrTrait<1971962>::by3 << '\n'<< 
            "width: " << NrTrait<1971962>::width << '\n';
}



