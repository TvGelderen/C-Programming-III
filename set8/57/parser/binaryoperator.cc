#include "parser.ih"

RuleValue &Parser::binaryOperator(RuleValue &lvalue, RuleValue &rvalue, char token)
{
    lvalue.d_number = calculateBinary(lvalue, rvalue, token);
    lvalue.d_type = RuleValue::VALUE;

    return lvalue;
}
