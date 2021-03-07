#include <iostream>
#include <concepts>

using namespace std;

template <typename Type>
concept HasDeref =
    requires(Type type)
    {
        *type;
    };

template <HasDeref Type>
auto fun1(Type type)
{
    return *type;
}

template <typename Type>
    requires HasDeref<Type>
auto fun2(Type type)
{
    return *type;
}

int main()
{
    int val = 42;
    int *ptr = &val;

    cout << fun1(ptr) << '\n';
    cout << fun2(ptr) << '\n';
}
