#ifndef INCLUDED_DATAVECTOR_
#define INCLUDED_DATAVECTOR_

#include <vector>
#include <memory>
#include <string>
#include <iosfwd>

class Data
{
    typedef std::vector<std::shared_ptr<std::string>> DataVector;

    DataVector d_data;

    public:
        typedef std::string value_type;       // added for back_inserter
        typedef value_type const &const_ref;  //          "

        Data() = default;
        Data(std::istream &is);

        void push_back(std::string const &str);
};

#endif
