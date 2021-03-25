#include "parser/parser.h"
#include <iostream>

using namespace std;

int main()
{
    /*
    Scanner scanner;
    while (int token = scanner.lex())
    {
        cout << token << ':' << scanner.matched();           
    }
    cout << '\n';               //close the line!
    */


    Parser parser;
    //parser.setDebug(true);
    return parser.parse();
}