template <typename Data>
class iterator: public std::iterator<std::random_access_iterator_tag, Data>
{
    public:
        iterator &operator++()
        iterator &operator--()
        iterator operator++(int)
        iterator operator--(int)

        bool operator==(iterator const &rhv) const
        bool operator!=(iterator const &rhv) const
        bool operator<(iterator const &rhv) const
        int operator-(iterator const &rhv) const
        iterator operator+(int step) const;
        iterator operator-(int step) const;

        Data &operator*();
        Data *operator->();
        iterator &operator=(iterator const &other) = default;   //we merely access the data
        iterator(iterator const &other) = default;              //so these can be default
};

