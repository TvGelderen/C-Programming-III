#include "parser.ih"

double Parser::calculateBinary(RuleValue &lvalue, RuleValue &rvalue, char token)
{
    switch(token)
    {
        case '+':
            return valueOf(lvalue) + valueOf(rvalue);
        case '-':
            return valueOf(lvalue) - valueOf(rvalue);
        case '*':
            return valueOf(lvalue) * valueOf(rvalue);
        case '/':
            return valueOf(lvalue) / valueOf(rvalue);
        case '%':
            return roundedValueOf(lvalue) % roundedValueOf(rvalue);
        case '<':
            return roundedValueOf(lvalue) << roundedValueOf(rvalue);
        case '>':
            return roundedValueOf(lvalue) >> roundedValueOf(rvalue);
        case '|':
            return roundedValueOf(lvalue) | roundedValueOf(rvalue);
        case '&':
            return roundedValueOf(lvalue) & roundedValueOf(rvalue);
        case '^':
            return roundedValueOf(lvalue) ^ roundedValueOf(rvalue);
        case '=':
            return valueOf(rvalue);
        default:
            return valueOf(rvalue);
    }
}