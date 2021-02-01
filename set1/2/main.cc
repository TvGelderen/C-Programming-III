#include <iostream>

using namespace std; 

template <typename T, typename U>
T as (U &value) {
 return static_cast<T>(value);
}

int main()
{
    int chVal = 'X';
    cout << as<char>(chVal) << '\n';
}

//Note: small program, so we've put everything in main!