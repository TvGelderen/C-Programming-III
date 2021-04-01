#include "parser.ih"

RuleValue &Parser::assign(RuleValue &lvalue, RuleValue &rvalue, char token)
{
    double value = calculateBinary(lvalue, rvalue, token);

    if (lvalue.d_type == RuleValue::VARIABLE)
        d_value[lvalue.d_idx] = value;
    else if (d_display)
    {
        ++d_nErrors_;
        error("Non-lvalue in assignment");
    }
    
    return lvalue;
}
