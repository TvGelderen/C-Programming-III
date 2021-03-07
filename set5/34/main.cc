#include <iostream>
#include <vector>
#include <concepts>

using namespace std;

template <typename Type, template<typename> class Container>
concept ReturnsRef =
    requires(Container<Type> container)
    {
        { container[0] } -> same_as<Type &>;
    };

template <typename Type, template<typename> class Container>
    requires ReturnsRef<Type, Container>
Type &fun(Container<Type> &container)
{
    return container[0];
}

int main()
{
    vector<int> vec(1, 1);

    cout << fun(vec) << '\n';
}
