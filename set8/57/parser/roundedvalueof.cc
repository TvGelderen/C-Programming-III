#include "parser.ih"

int Parser::roundedValueOf(RuleValue const &e)
{
    double value = valueOf(e);
    return static_cast<int>(value + 0.5 - (value < 0.0));
}
