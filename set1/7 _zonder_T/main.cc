
#include <iostream>
#include <set>
    
using namespace std;
    
ostream & operator << (ostream &out, set<size_t> const Set) 
{ 
    out << '{';                          //the first opening bracket
    for (auto elem : Set)
    {
        out << elem;
        if (elem != *Set.rbegin())
            out << ", ";
    }
    out << '}';                         //closing bracket of the set
    return out;
} 

ostream & operator << (ostream &out, set<set<size_t>> const Set) 
{ 
    out << '{';                          //the first opening bracket
    for (auto elem : Set)
    {
        out << elem;
        if (elem != *Set.rbegin())
            out << ", ";
    }
    out << '}';                         //closing bracket of the set
    return out;
} 

int main()
{
    set<size_t> const universe = { 1, 2, 3,  };
    set<set<size_t>> const subsets =
    {
        { 1, 2,      },
        {       3, 4 },
    };

        cout << "Universe: " << universe << '\n'
                << "subsets: " << subsets << '\n';  // WC: no operator<<
                            // desired output: Universe: {1, 2, 3, 4}
                            //                 subsets: {{1, 2}, {3, 4}}
}