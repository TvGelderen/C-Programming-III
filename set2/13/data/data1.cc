#include "data.ih"

Data::Data(istream &is)
{                                   // copy the contents from the istream
    copy(istream_iterator<string>{ is },
         istream_iterator<string>{},
         back_inserter(*this));
}
