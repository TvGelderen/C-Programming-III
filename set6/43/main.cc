#include "Scanner.h"
#include <iostream>

using namespace std; 

int main()
try
{
    Scanner scanner;
    scanner.switchIstream("test.txt");

    while (int token = scanner.lex())
    {
        if (token == COMMENT)
            continue;
        cout << scanner.matched();           
    }
    cout << '\n';               //close the line!
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}