#include "parser.ih"
#include <algorithm>

void Parser::list()
{
    std::vector<pair<string, unsigned>> variables(d_symtab.begin(), d_symtab.end());
    std::sort(variables.begin(), variables.end());
    for (const auto & p : variables)
        cout << p.first << " = " << d_value[p.second] << '\n';
    prompt();
}
