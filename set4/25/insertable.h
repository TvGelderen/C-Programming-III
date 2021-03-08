#ifndef INCLUDED_INSERTABLE_
#define INCLUDED_INSERTABLE_

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

#endif
