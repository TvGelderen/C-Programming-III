#ifndef INCLUDED_STORAGE_
#define INCLUDED_STORAGE_

#include <vector>
#include <initializer_list>


class Storage
{
    std::vector<size_t> d_data;

    public:
        Storage() = default;
        Storage(std::initializer_list<size_t> const &list);

        template <typename Type>
        size_t operator[](Type idx) const;

        template <typename Type>
        size_t &operator[](Type idx);
};

template <typename Type>
inline size_t Storage::operator[](Type idx) const
{
    return d_data[static_cast<size_t>(idx)];
}

template <typename Type>
inline size_t &Storage::operator[](Type idx)
{
    return d_data[static_cast<size_t>(idx)];
}
#endif