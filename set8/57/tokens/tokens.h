#ifndef INCLUDED_TOKENS_
#define INCLUDED_TOKENS_

struct Tokens
{
    // Symbolic tokens:
    enum Tokens_
    {
        NUMBER = 257,
        EXIT,
        LIST,
        IDENT,
        INCREMENT,
        DECREMENT,
        ASSIGN_ADD,
        ASSIGN_SUB,
        ASSIGN_MUL,
        ASSIGN_DIV,
        ASSIGN_MOD,
        ASSIGN_BITLSHIFT,
        ASSIGN_BITRSHIFT,
        ASSIGN_BITOR,
        ASSIGN_BITXOR,
        ASSIGN_BITAND,
        uMinus,
        uNegate,
    };

};

#endif
