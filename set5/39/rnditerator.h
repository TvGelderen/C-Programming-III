#ifndef _INCLUDED_RNDITERATOR_
#define _INCLUDED_RNDITERATOR_

#include <concepts>

template <typename Type>
concept Incrementable =
    requires(Type obj)
    {
        { ++obj } -> std::same_as<Type &>;
        { obj++ } -> std::same_as<Type>;
        { *obj++ } -> std::convertible_to<typename Type::value_type const &>;
    };

template <typename Type>
concept Decrementable =
    requires(Type obj)
    {
        { --obj } -> std::same_as<Type &>;
        { obj-- } -> std::same_as<Type>;
        { *obj-- } -> std::convertible_to<typename Type::value_type const &>;
    };

template <typename Type>
concept Arithmetic =
    requires(Type obj, Type obj2)
    {
        { obj + 1 } -> std::same_as<Type>;
        { 1 + obj } -> std::same_as<Type>;
        { obj - 1 } -> std::same_as<Type>;
        { obj - obj2 } -> std::convertible_to<typename
                                                Type::value_type const &>;
        { obj += 1 } -> std::same_as<Type &>;
        { obj -= 1 } -> std::same_as<Type &>;
    };

template <typename Type>
concept Dereferenceable =
    requires(Type obj)
    {
        { *obj } -> std::convertible_to<typename Type::value_type const &>;
        { obj[0] } -> std::convertible_to<typename Type::value_type const &>;
    };

template <typename Type>
concept RndIterator = std::regular<Type>
                        and std::totally_ordered<Type>
                        and Incrementable<Type>
                        and Decrementable<Type>
                        and Arithmetic<Type>
                        and Dereferenceable<Type>;

#endif
