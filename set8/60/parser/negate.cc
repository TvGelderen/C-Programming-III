#include "parser.ih"

RuleValue &Parser::negate(RuleValue &e)
{
    return e = -valueOf(e);
}
