#ifndef _INCLUDED_TRAITS_
#define _INCLUDED_TRAITS_

template <typename Type>
class Traits
{
    template<typename Trait>
    struct TypeTraits
    {
        enum {
            value = 1
        };
    };

    template<typename Trait>
    struct TypeTraits<Trait*>
    {
        enum {
            value = 2
        };
    };

    template<typename Trait>
    struct TypeTraits<Trait&>
    {
        enum {
            value = 3
        };
    };
    
    template<typename Trait>
    struct TypeTraits<Trait&&>
    {
        enum {
            value = 4
        };
    };

    public:
        enum {
            value = TypeTraits<Type>::value
        };

};

#endif