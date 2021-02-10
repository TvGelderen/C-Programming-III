#include <iostream>
#include <set>

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, set<T> const &Set)
{
    out << '{';                          //the first opening bracket
    for (auto elem : Set)
    {
        out << elem;                    // display elems
        if (elem != *Set.rbegin())
            out << ", ";                // sep except for last elem
    }
    out << '}';                         //closing bracket of the set
    return out;
}

int main()
{
    set<size_t> const universe = { 1, 2, 3, 4};
    set<set<size_t>> const subsets =
    {
        { 1, 2,      },
        {       3, 4 },
    };

        cout << "Universe: " << universe << '\n'
             << "subsets:  " << subsets << '\n';
}
