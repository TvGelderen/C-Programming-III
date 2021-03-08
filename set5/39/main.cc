#include <iostream>
#include <vector>
#include <algorithm>

#include "rnditerator.h"

using namespace std;

template <RndIterator RAI>
void rSort(RAI &&begin, RAI &&end)
{
    sort(forward<RAI>(begin), forward<RAI>(end));
}

int main()
{
    vector<int> iv = { 4, 3, 2, 1 };

    rSort(iv.begin(), iv.end());

    for (size_t idx = 0; idx != iv.size(); ++idx)
        cout << iv[idx] << ' ';
    cout << '\n';
}
