#include "storage/storage.ih" 
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

using namespace std; 

int main()
{
    Storage storage;
    storage.push_back("Hoi");
    storage.push_back("String 2");
    storage.push_back("Abc");
    
    sort(storage.begin(), storage.end());                                       //sort the vector 
    copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));  //display the results!


    /*
    sort(storage.rbegin(), storage.rend());

    copy(storage.begin(), storage.end(), std::ostream_iterator<string>(std::cout, " "));
    */
}
        