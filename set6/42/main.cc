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
        switch (token)
        {
        case IDENTIFIER:
            cout << "Identifier: " << scanner.matched() << '\n';
        case INTEGRAL:
            cout << "Integral: " << scanner.matched() << '\n';
        case OPERATOR:
            cout << "Operator: " << scanner.matched() << '\n';
        }
    }
}

int main(int argc, char **argv)
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
