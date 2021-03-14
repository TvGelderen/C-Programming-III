#include "Scanner.h"
#include <iostream>

using namespace std; 

int main()
{
    Scanner scanner;
    scanner.switchIstream("test.txt");

    while (int token = scanner.lex())
    {
        if (token == COMMENT)
            continue;
        //cout << '!' << token << scanner.matched() << '!' <<'\n';
        cout << scanner.matched() <<'\n';               
    }

}