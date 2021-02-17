#include "storage/storage.ih" 
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

using namespace std; 

int main()
{
    //example with strings
    Storage<string> storage;
    storage.push_back("Hoi");
    storage.push_back("String");
    storage.push_back("Abc");

    sort(storage.begin(), storage.end());                                       //sort the vector 
    copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));  //display the results!
        cout << '\n';
    sort(storage.rbegin(), storage.rend());                                      //sort the vector 
    copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));  //display the results!
        cout << '\n';
     
    //second example with ints :D
    Storage<int> storage2;
    storage2.push_back(5);
    storage2.push_back(32);
    storage2.push_back(18);
    
    sort(storage2.begin(), storage2.end());                                       //sort the vector 
    copy(storage2.begin(), storage2.end(), ostream_iterator<int>(cout, " "));  //display the results!
        cout << '\n';
}
        