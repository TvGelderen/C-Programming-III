#ifndef INCLUDED_INSERTABLE_
#define INCLUDED_INSERTABLE_

#include <ostream>

template <template <typename> class Container, typename Type>
struct Insertable: public Container<Type>
{
    Insertable();
    Insertable(Insertable const &other);
    Insertable(Insertable &&tmp);

    Insertable(Container<Type> const &data);
    Insertable(Container<Type> &&data);
    Insertable(Type const &value);
    Insertable(Type &&value);
};
                                                // default constructor
template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable()
:
    Container<Type>()
{}
                                                // copy constructor
template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(
                                Insertable<Container, Type> const &other)
:
    Container<Type>(other)
{}
                                                // move constructor
template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(
                                Insertable<Container, Type> &&tmp)
:
    Insertable(tmp)
{}

template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(Container<Type> const &data)
:
    Container<Type>(data)
{}

template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(Container<Type> &&data)
:
    Insertable(data)
{}

template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(Type const &value)
:
    Container<Type>(1, value)
{}

template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(Type &&value)
:
    Insertable(value)
{}

                                    // Insertable insertion operator
template <template <typename> class Container, typename Type>
inline std::ostream &operator<<(std::ostream &out,
                                Insertable<Container, Type> const &obj)
{
    for (size_t idx = 0; idx != obj.size(); ++idx)
        out << obj[idx] << ' ';

    return out;
}

#endif
