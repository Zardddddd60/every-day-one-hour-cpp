#include "13-26.h"
#include <string>
#include <vector>

const StrBlob& StrBlob::operator= (const StrBlob& sb)
{
    this->data = std::make_shared<element_type>(*sb.data);
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this, 0);
}

ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this, this->data->size());
}
