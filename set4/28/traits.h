#ifndef _INCLUDED_TRAITS_
#define _INCLUDED_TRAITS_

template <typename Type>
class Traits
{
    template <typename Trait>
    struct TypeTraits;

    public:
        enum
        {
            value = TypeTraits<Type>::value
        };

};

template <typename Type>
template <typename Trait>
struct Traits<Type>::TypeTraits
{
    enum
    {
        value = 1
    };
};

template <typename Type>
template <typename Trait>
struct Traits<Type>::TypeTraits<Trait *>
{
    enum
    {
        value = 2
    };
};

template <typename Type>
template <typename Trait>
struct Traits<Type>::TypeTraits<Trait &>
{
    enum
    {
        value = 3
    };
};

template <typename Type>
template <typename Trait>
struct Traits<Type>::TypeTraits<Trait &&>
{
    enum
    {
        value = 4
    };
};

#endif
