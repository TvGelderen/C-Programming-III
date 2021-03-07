#include <iostream>
#include <vector>
#include <concepts>

using namespace std;

template <typename Container>
concept ReturnsRef =
    requires(Container container)
    {
        { container[0] } -> same_as<typename Container::value_type &>;
    };

template <ReturnsRef Container>
auto fun(Container &container)
{
    return container[0];
}

int main()
{
    vector<int> vec(1, 1);

    cout << fun(vec) << '\n';
}
