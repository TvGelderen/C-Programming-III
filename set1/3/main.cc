#include <iostream>

using namespace std;

template <typename T>
T *rawCapacity(size_t size)
{
    return static_cast<T *>(operator new(size * sizeof(T)));
}

int main()
{
    string *strPtr = rawCapacity<string>(1);
    strPtr[0] = "First string";
    cout << strPtr[0] << '\n';
}
