#include "storage.ih" 
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

using namespace std; 

int main()
{
    Storage<string> storage;
    storage.push_back("Hoi");
    storage.push_back("String 2");

    for (size_t idx = 0, end = storage.d_storage.size(); idx != end; ++idx)
        cout << idx << " address: " << storage.d_storage[idx] << 
                        "\t value: " << *storage.d_storage[idx] << '\n';


    /*

    sort(storage.begin(), storage.end());
    sort(storage.rbegin(), storage.rend());

    copy(storage.begin(), storage.end(), std::ostream_iterator<string>(std::cout, " "));
    */
}
        