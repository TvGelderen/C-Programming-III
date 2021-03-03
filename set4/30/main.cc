#include <iostream>
#include "expr/expr.h"

using namespace std;

typedef vector<int> IVect;
typedef vector<double> DVect;

int main()
{
    IVect iv1(10, 4);        // IVect: vector<int>
    IVect iv2(10, 3);
    IVect iv3(10, 2);
    IVect iv4(10, 1);

    IVect iResult { iv1 * (iv2 + iv3) / iv4 };

    for (size_t idx = 0; idx != iResult.size(); ++idx)
        cout << iResult[idx] << ' ';
    cout << '\n';

    DVect dv1(10, 4.1);     // DVect: vector<double>
    DVect dv2(10, 3.1);
    DVect dv3(10, 2.1);
    DVect dv4(10, 1.1);

    DVect dResult { dv1 * (dv2 + dv3) / dv4 };

    for (size_t idx = 0; idx != dResult.size(); ++idx)
        cout << dResult[idx] << ' ';
    cout << '\n';
}
