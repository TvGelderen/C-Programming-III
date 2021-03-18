#include "Scanner.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    Scanner scanner(in);

    while (int token = scanner.lex())
    {
        if (token == -1) 
            cout << scanner.matched();
        else
            cout << "grabbed(" << token << ",\"main.gsl\")";
    }

    cout << '\n';               //close the line!
}