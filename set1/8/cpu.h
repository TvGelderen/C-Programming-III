#ifndef INCLUDED_CPU_
#define INCLUDED_CPU_


class CPU
{
    static void (CPU::*s_opcode[])();
    
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
        void exit() const;      //     1d
        void noop() const;      //     0c - 1c

        void exitHelper(); 
        void noopHelper();
};

inline void CPU::push(int opcodeByte)
{
    (this->*s_opcode[opcodeByte])();        // call the correct function
}

inline void CPU::exitHelper()
{
    exit();
}

inline void CPU::noopHelper()
{
    noop();
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
    &CPU::noopHelper,      //     0c
    &CPU::noopHelper,      //     0d
    &CPU::noopHelper,      //     0e
    &CPU::noopHelper,      //     0f
    &CPU::noopHelper,      //     10
    &CPU::noopHelper,      //     11
    &CPU::noopHelper,      //     12
    &CPU::noopHelper,      //     13
    &CPU::noopHelper,      //     14
    &CPU::noopHelper,      //     15
    &CPU::noopHelper,      //     16
    &CPU::noopHelper,      //     17
    &CPU::noopHelper,      //     18
    &CPU::noopHelper,      //     19
    &CPU::noopHelper,      //     1a
    &CPU::noopHelper,      //     1b
    &CPU::noopHelper,      //     1c
    &CPU::exitHelper,      //     1d    
};


// TODO remove this later, just to compile without linker errors.
inline void CPU::jmp() { }             //     00
inline void CPU::jmpFalse() { }        //     01
inline void CPU::jmpTrue() { }         //     02
inline void CPU::push1jmpEnd() { }     //     03
inline void CPU::push0() { }           //     04
inline void CPU::pushImm() { }         //     05
inline void CPU::pushStrConst() { }    //     06
inline void CPU::pushVar() { }         //     07
inline void CPU::pushReg() { }         //     08
inline void CPU::popVar() { }          //     09
inline void CPU::umin() { }            //     0a
inline void CPU::atoi() { }            //     0b
inline void CPU::noop() const { }      //     0c - 1c
#endif