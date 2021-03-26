#include "parser.ih"

double Parser::valueOf(RuleValue const &e)
{
    return e.d_type == RuleValue::VALUE ? 
                e.d_number 
            : 
                d_value[e.d_idx];
}
