#ifndef INCLUDED_GLOBAL_COUNTER_
#define INCLUDED_GLOBAL_COUNTER_

//#include <cstddef>

class GlobalCounter
{
    static size_t s_global_count;    
    static size_t s_global_actual;
    
    public:
        GlobalCounter();
        ~GlobalCounter();

        size_t globalcount() const;
        size_t globalactual() const;
};

size_t GlobalCounter::s_global_count = 0;
size_t GlobalCounter::s_global_actual = 0;

inline GlobalCounter::GlobalCounter()
{
    ++s_global_count;
    ++s_global_actual;
}

inline GlobalCounter::~GlobalCounter()
{
    --s_global_actual;
}

inline size_t GlobalCounter::globalcount() const
{
    return s_global_count;
}

inline size_t GlobalCounter::globalactual() const
{
    return s_global_actual;
}

#endif