#include <fstream>
#include <iterator>
#include <algorithm>

#include "data/data.h"

using namespace std;

int main()
{
    ifstream ifs{ "input.txt" };

    Data data1{ ifs };

    Data data2;

    copy(istream_iterator<string>{ ifs },
         istream_iterator<string>{},
         back_inserter(data2));
}
