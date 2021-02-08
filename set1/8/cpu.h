#ifndef INCLUDED_CPU_
#define INCLUDED_CPU_


class CPU
{
    static void (*s_opcode[])();
    
    public:
        void push(int opcodeByte);          //execute opcodes

    private:
        void jmp();             //     00
        void jmpFalse();        //     01
        void jmpTrue();         //     02
        void push1jmpEnd();     //     03
        void push0();           //     04
        void pushImm();         //     05
        void pushStrConst();    //     06
        void pushVar();         //     07
        void pushReg();         //     08
        void popVar();          //     09
        void umin();            //     0a
        void atoi();            //     0b
        void exit();            //     1d    
};

inline void CPU::push(int opcodeByte)
{
    (*s_opcode[opcodeByte])();        //call the correct function
}

inline void (CPU::*CPU::s_opcode[])() = 
{
    &CPU::jmp,             //     00
    &CPU::jmpFalse,        //     01
    &CPU::jmpTrue,         //     02
    &CPU::push1jmpEnd,     //     03
    &CPU::push0,           //     04
    &CPU::pushImm,         //     05
    &CPU::pushStrConst,    //     06
    &CPU::pushVar,         //     07
    &CPU::pushReg,         //     08
    &CPU::popVar,          //     09
    &CPU::umin,            //     0a
    &CPU::atoi,            //     0b
    &CPU::exit,            //     1d    

};

#endif