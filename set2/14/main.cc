#include "storage.ih" 
#include <algorithm>
#include <iterator>

int main()
{
    Storage<std::string> storage;
    storage.push_back("Hoi");
    storage.push_back("String 2");
    
    sort(storage.begin(), storage.end());
    sort(storage.rbegin(), storage.rend());

    copy(storage.begin(), storage.end(), std::ostream_iterator<string>(std::cout, " "));
}
        