#include "Scanner.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;


int main(int argc, char **argv)
{                                
    Scanner scanner;         

    vector<string> words;

    while (int token = scanner.lex()) 
    {                    
        if (token  == SPACE)
            continue;               

        words.push_back(scanner.matched());    // process other tokens
    }
    
    scanner.switchIstream();
                        
    sort(words.begin(), words.end());
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
        cout << '\n';                          // closing line!
}