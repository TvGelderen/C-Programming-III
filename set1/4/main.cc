#include "forward.h"
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;


void fun(int first, int second)
{
    cout << "Fun: " << first + second << '\n';
}
                                            // increments each argument:
void incrementer(int &one, int &two, int &three)
{
    ++one;
    ++two;
    ++three;
}

struct Demo
{
    string str;
};

void fun2(Demo &&dem1, Demo &&dem2)
{
    cout << "dem1: " << dem1.str << " dem2: " << dem2.str << '\n';
}

int main()
{
    forwarder(fun, 1, 3);       // should show 'fun(1, 3)' to cout
    // cout << forwarder(plus<string>(), "hello ", "world");

                             // fun2 expects two rvalue references 
    forwarder(fun2, Demo{"hello"}, Demo{"World"});

    forwarder(plus<string>(), "hello ", "world");   //note we ini

    vector<int> first = {1,2,3};

    forwarder(                  // receives a lambda function
        [](vector<int> &first, vector<int> const &second, 
                                    vector<int> const &third)
        {
            first.push_back(inner_product(second.begin(),second.end(), third.begin(), 0));
                // elements
        }, first, vector<int>{3,4,5}, vector<int>{6,7,8}
    );
    copy(first.begin(), first.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';

    int x = 0;
    forwarder(incrementer, x, x, x);
    cout << x << '\n';          // should show '3'
}