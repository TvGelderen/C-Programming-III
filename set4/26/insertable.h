#ifndef INCLUDED_INSERTABLE_
#define INCLUDED_INSERTABLE_

#include <ostream>

template <template <typename ...> class Container, typename ...Types>
struct Insertable: public Container<Types ...>
{
    Insertable();
    Insertable(Insertable const &other);
    Insertable(Insertable &&tmp);

    template <typename ...Params>
    Insertable(Params ...params);

    Insertable(Container<Types ...> const &data);
    Insertable(Container<Types ...> &&data);
    Insertable(Types const &...values);
    Insertable(Types &&...values);
};
                                                // default constructor
template <template <typename ...> class Container, typename ...Types>
inline Insertable<Container, Types ...>::Insertable()
:
    Container<Types ...>()
{}
                                                // copy constructor
template <template <typename ...> class Container, typename ...Types>
inline Insertable<Container, Types ...>::Insertable(
                                Insertable<Container, Types ...> const &other)
:
    Container<Types ...>(other)
{}
                                                // move constructor
template <template <typename ...> class Container, typename ...Types>
inline Insertable<Container, Types ...>::Insertable(
                                Insertable<Container, Types ...> &&tmp)
:
    Container<Types ...>(std::move(tmp))
{}

                                        // all other possible constructors
template <template <typename ...> class Container, typename ...Types>
template <typename ...Params>
inline Insertable<Container, Types ...>::Insertable(Params ...params)
:
    Container<Types ...>(std::forward<Params>(params)...)
{}

template <template <typename ...> class Container, typename ...Types>
inline Insertable<Container, Types ...>::Insertable(Container<Types ...> const &data)
:
    Container<Types ...>(data)
{}

template <template <typename ...> class Container, typename ...Types>
inline Insertable<Container, Types ...>::Insertable(Container<Types ...> &&data)
:
    Container<Types ...>(std::move(data))
{}

template <template <typename ...> class Container, typename ...Types>
inline Insertable<Container, Types ...>::Insertable(Types const &...values)
:
    Container<Types ...>(1, std::forward<Types>(values)...)
{}

template <template <typename ...> class Container, typename ...Types>
inline Insertable<Container, Types ...>::Insertable(Types &&...values)
:
    Container<Types ...>(1, std::forward<Types>(values)...)
{}

                                    // Insertable insertion operator
template <template <typename ...> class Container, typename ...Types>
inline std::ostream &operator<<(std::ostream &out,
                                Insertable<Container, Types ...> const &obj)
{
    for (auto iter = obj.begin(); iter != obj.end(); ++iter)
        out << *iter << ' ';

    return out;
}

#endif
