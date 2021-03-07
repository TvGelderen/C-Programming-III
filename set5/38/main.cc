#include "main.ih"

int main()
{
    math<Add>(4, 2, 5, 6);      // shows: 6  9 10
    math<Sub>(4, 2, 5, 6);      // shows: 2 -1 -2
    // math<Add>(4, 2, "5", 6); // WC: constraint not satisfied.
}
