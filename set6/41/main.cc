#include "Scanner.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

void processInputStream(istream &stream)
{
    vector<string> words;
    Scanner scanner(stream);

    while (int token = scanner.lex()) 
    {                    
        if (token == WORD)
            words.push_back(scanner.matched());    // process other tokens
    }
                        // sorts the list of words
    sort(words.begin(), words.end());
                        // removes the duplicates
    words.erase(unique(words.begin(), words.end()), words.end());
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
        cout << '\n';   // closing line!
}

int main(int argc, char **argv)
try
{
                        // process the input stream
    if (argc == 1)
        processInputStream(std::cin);
    
                        // process all files
    for (size_t i = 1; argv[i]; ++i)
    {
        ifstream stream(argv[i]);
        processInputStream(stream);
        stream.close();
    }
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}
