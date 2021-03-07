#include <concepts>

template <typename Type>
concept Add =
    requires(Type type)
    {
        type + type;
        type - type;
    };

template <typename Type>
concept Mul =
    requires(Type type)
    {
        type * type;
        type / type;
    };

template <typename Type>
concept AddMul = Add<Type> or Mul<Type>;

template <typename Type>
concept AddOrMul = (Add<Type> and not Mul<Type>)
                    or (not Add<Type> and Mul<Type>);
