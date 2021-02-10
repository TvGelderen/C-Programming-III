#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <sstream>
#include <exception>

class Exception: public std::exception
{
    std::string d_what;

    public:
        Exception() = default;

        template <typename T>
        friend Exception &&operator<<(Exception &&in, T rhs);

        template <typename T>
        std::string to_string(T const &value);

        char const *what() const noexcept(true) override;
};

template <typename T>
inline Exception &&operator<<(Exception &&in, T rhs)
{
    in.d_what += in.to_string(rhs);    //std::to_string
    return std::move(in);
}

template <typename T>
inline std::string Exception::to_string(T const &value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}

#endif
