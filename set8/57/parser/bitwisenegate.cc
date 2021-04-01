#include "parser.ih"

RuleValue &Parser::bitwisenegate(RuleValue &e)
{
    return e = static_cast<double>(~roundedValueOf(e));
}
