// Generated by Flexc++ V2.07.03 on Fri, 19 Mar 2021 11:43:24 +0000

#ifndef ScannerBASE_H_INCLUDED
#define ScannerBASE_H_INCLUDED

#include <limits>
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <memory>



class ScannerBase
{
                // idx: rule, value: tail length (NO_INCREMENTS if no tail)
    typedef std::vector<int> VectorInt;

    static size_t const s_unavailable = std::numeric_limits<size_t>::max();

    enum 
    {
        AT_EOF = -1
    };

protected:
    enum Leave_
    {};

    enum class ActionType_
    {
        CONTINUE,               // transition succeeded, go on
        ECHO_CH,                // echo ch itself (d_matched empty)
        ECHO_FIRST,             // echo d_matched[0], push back the rest
        MATCH,                  // matched a rule
        RETURN,                 // no further continuation, lex returns 0.
    };

    enum class PostEnum_
    {
        END,                    // postCode called when lex_() ends 
        POP,                    // postCode called after switching files
        RETURN,                 // postCode called when lex_() returns
        WIP                     // postCode called when a non-returning rule
                                // was matched
    };

public:
    // $insert startcondenum
    enum class StartCondition_{
        INITIAL,
    };

private:
    struct FinalData
    {
        size_t rule;
        size_t length;
    };
    struct Final
    {
        FinalData std;
        FinalData bol;
    };

        // class Input encapsulates all input operations. 
        // Its member get() returns the next input character
// $insert inputInterface

    class Input
    {
        std::deque<unsigned char> d_deque;  // pending input chars
        std::istream *d_in;                 // ptr for easy streamswitching
        size_t d_lineNr;                    // line count

        public:
            Input();
                                       // iStream: dynamically allocated
            Input(std::istream *iStream, size_t lineNr = 1);
            size_t get();                   // the next range
            void reRead(size_t ch);         // push back 'ch' (if < 0x100)
                                            // push back str from idx 'fmIdx'
            void reRead(std::string const &str, size_t fmIdx);
            size_t lineNr() const
            {
                return d_lineNr;
            }
            size_t nPending() const
            {
                return d_deque.size();
            }
            void setPending(size_t size)
            {
                d_deque.erase(d_deque.begin(), d_deque.end() - size);
            }
            void close()                    // force closing the stream
            {
                delete d_in;
                d_in = 0;                   // switchStreams also closes
            }

        private:
            size_t next();                  // obtain the next character
    };

protected:
    struct StreamStruct
    {
        std::string pushedName;
        Input pushedInput;
    };

private:
    std::vector<StreamStruct>    d_streamStack;

    std::string     d_filename;             // name of the currently processed
    static size_t   s_istreamNr;            // file. With istreams it receives
                                            // the name "<istream #>", where
                                            // # is the sequence number of the 
                                            // istream (starting at 1)
    int             d_startCondition = 0;
    int             d_lopSC = 0;

    size_t          d_state = 0;
    int             d_nextState;
    std::shared_ptr<std::ostream> d_out;
    bool            d_atBOL = true;         // the matched text starts at BOL
    Final d_final;

                                            // only used interactively:
    std::istream *d_in;                     // points to the input stream
    std::shared_ptr<std::istringstream> d_line; // holds line fm d_in
    
    Input           d_input;
    std::string     d_matched;              // matched characters
    std::string     d_lopMatched;           // matched lop-rule characters 
    std::string::iterator d_lopIter;
    std::string::iterator d_lopTail;
    std::string::iterator d_lopEnd;

    size_t          d_lopPending;           // # pending input chars at lop1_
    bool            d_return;               // return after a rule's action 
    bool            d_more = false;         // set to true by more()

    size_t (ScannerBase::*d_get)() = &ScannerBase::getInput;

protected:
    std::istream   *d_in_;
    int d_token_;                          // returned by lex_



    int     const (*d_dfaBase_)[56];

    static int     const s_dfa_[][56];
    static int     const (*s_dfaBase_[])[56];
    enum: bool { s_interactive_ = false };
    enum: size_t {
        s_rangeOfEOF_           = 53,
        s_finIdx_               = 54,
        s_nRules_               = 11,
        s_maxSizeofStreamStack_ = 10
    };
    static size_t  const s_ranges_[];
    static size_t  const s_rf_[][2];

public:
    ScannerBase(ScannerBase const &other)             = delete;
    ScannerBase &operator=(ScannerBase const &rhs)    = delete;

    bool                debug()     const;
    std::string const  &filename()  const;
    std::string const  &matched()   const;

    size_t              length()    const;
    size_t              lineNr()    const;

    void                setDebug(bool onOff);

    void                switchOstream(std::ostream &out);
    void                switchOstream(std::string const &outfilename);


    void                switchStreams(std::istream &in,
                                      std::ostream &out = std::cout);

    void                switchIstream(std::string const &infilename);
    void                switchStreams(std::string const &infilename,
                                      std::string const &outfilename);


// $insert interactiveDecl

protected:
    ScannerBase(std::istream &in, std::ostream &out);
    ScannerBase(std::string const &infilename, std::string const &outfilename);
    ~ScannerBase();

    bool            popStream();
    std::ostream   &out();
    void            echo() const;
    void            leave(int retValue) const;

//    `accept(n)' returns all but the first `n' characters of the current
// token back to the input stream, where they will be rescanned when the
// scanner looks for the next match.
//  So, it matches n of the characters in the input buffer, and so it accepts
//  n characters, rescanning the rest. 
    void            accept(size_t nChars = 0);      // former: less
    void            redo(size_t nChars = 0);        // rescan the last nChar
                                                    // characters, reducing
                                                    // length() by nChars
    void            more();
    void            push(size_t ch);                // push char to Input
    void            push(std::string const &txt);   // same: chars


    std::vector<StreamStruct> const &streamStack() const;

    void            pushStream(std::istream &curStream);
    void            pushStream(std::string const &curName);


    void            setFilename(std::string const &name);
    void            setMatched(std::string const &text);

    static std::string istreamName_();
        
        // members used by lex_(): they end in _ and should not be used
        // otherwise.

    ActionType_    actionType_(size_t range); // next action
    bool            return_();                 // 'return' from codeblock
    size_t          matched_(size_t ch);       // handles a matched rule
    size_t          getRange_(int ch);         // convert char to range
    size_t          get_();                    // next character
    size_t          state_() const;            // current state 
    void            continue_(int ch);         // handles a transition
    void            echoCh_(size_t ch);        // echoes ch, sets d_atBOL
    void            echoFirst_(size_t ch);     // handles unknown input
    void            updateFinals_();           // update a state's Final info
    void            noReturn_();               // d_return to false
    void            print_() const;            // optionally print token
    void            pushFront_(size_t ch);     // return char to Input
    void            reset_();                  // prepare for new cycle
                                                // next input stream:
    void            switchStream_(std::istream &in, size_t lineNr);   
    void            lopf_(size_t tail);        // matched fixed size tail
    void            lop1_(int lopSC);          // matched ab for a/b
    void            lop2_();                   // matches the LOP's b tail
    void            lop3_();                   // catch-all while matching b
    void            lop4_();                   // matches the LOP's a head

// $insert startconddecl
    StartCondition_ startCondition() const;   // current start condition
    void            begin(StartCondition_ startCondition);

private:
    static StartCondition_ constexpr SC(int sc);
    static int constexpr SC(StartCondition_ sc);

    size_t getInput();
    size_t getLOP();
    void p_pushStream(std::string const &name, std::istream *streamPtr);
    void setMatchedSize(size_t length);
    bool knownFinalState();

    template <typename ReturnType, typename ArgType>
    static ReturnType constexpr as(ArgType value);
    static bool constexpr available(size_t value);
};

inline ScannerBase::~ScannerBase()
{
    d_input.close();
}

template <typename ReturnType, typename ArgType>
inline ReturnType constexpr ScannerBase::as(ArgType value)
{
    return static_cast<ReturnType>(value);
}

// $insert startcondimpl
inline ScannerBase::StartCondition_ constexpr ScannerBase::SC(int sc)
{
    return as<StartCondition_>(sc);
}

inline int constexpr ScannerBase::SC(StartCondition_ sc)
{
    return as<int>(sc);
}

inline ScannerBase::StartCondition_ ScannerBase::startCondition() const
{
    return SC(d_startCondition);
}

inline void ScannerBase::begin(StartCondition_ startCondition)
{
    // d_state is reset to 0 by reset_()
    d_dfaBase_ = s_dfaBase_[d_startCondition = SC(startCondition)];
}

inline bool ScannerBase::knownFinalState()
{
    return (d_atBOL && available(d_final.bol.rule)) ||
           available(d_final.std.rule);
}

inline bool constexpr ScannerBase::available(size_t value)
{   
    return value != std::numeric_limits<size_t>::max();
}

inline std::ostream &ScannerBase::out()
{
    return *d_out;
}

inline void ScannerBase::push(size_t ch)
{
    d_input.reRead(ch);
}

inline void ScannerBase::push(std::string const &str)
{
    d_input.reRead(str, 0);
}

inline void ScannerBase::setFilename(std::string const &name)
{
    d_filename = name;
}

inline void ScannerBase::setMatched(std::string const &text)
{
    d_matched = text;
}

inline std::string const &ScannerBase::matched() const
{
    return d_matched;
}

inline std::string const &ScannerBase::filename() const
{
    return d_filename;
}

inline void ScannerBase::echo() const
{
    *d_out << d_matched;
}

inline size_t ScannerBase::length() const
{
    return d_matched.size();
}

inline void ScannerBase::leave(int retValue) const
{
    throw as<Leave_>(retValue);
}

inline size_t ScannerBase::lineNr() const
{
    return d_input.lineNr();
}

inline void ScannerBase::more()
{
    d_more = true;
}

inline size_t ScannerBase::state_() const
{
    return d_state;
}

inline size_t ScannerBase::get_()
{
    return (this->*d_get)();
}

inline size_t ScannerBase::getInput()
{
    return d_input.get();
}

inline bool ScannerBase::return_()
{
    return d_return;
}

inline void ScannerBase::noReturn_()
{
    d_return = false;
}


#endif //  ScannerBASE_H_INCLUDED
