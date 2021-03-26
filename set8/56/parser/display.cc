#include "parser.ih"

void Parser::display(RuleValue &e)
{
    if (d_display)
        cout << valueOf(e) << "\n";
    prompt();
}
