#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <exception>

class Exception: public std::exception
{
    std::string d_what;

    public:
        Exception() = default;

        template <typename T>
        friend Exception &&operator<<(Exception &&in, T rhs);

        char const *what() const noexcept(true) override;   
};

template <typename T>
inline Exception &&operator<<(Exception &&in, T rhs)
{
    in.d_what  += rhs;                        //std::to_string
    return std::move(in);
}

#endif