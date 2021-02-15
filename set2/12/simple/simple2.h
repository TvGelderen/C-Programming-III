template <class Type>
Simple<Type>::Simple(Type const &value)
:
    d_value(value)
{
    std::cout << "Simple second constructor" << '\n';
}
