#ifndef INCLUDED_CHARS_
#define INCLUDED_CHARS_

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

#endif
