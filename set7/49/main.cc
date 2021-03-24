#include "parser/parser.h"

int main()
{
    Parser parser;
    parser.setDebug(true);
    return parser.parse();
}