#include <string>

using namespace std;

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

template <BasicMath lhs, BasicMath rhs>
void fun(lhs, rhs)
{}

int main()
{
    fun(1, 1);
    fun(1, string{"hello world"});
}
