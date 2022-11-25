#include "Query.h"

namespace Engine {

Query::Query(
    const std::string text,
    const std::string filter,
    const unsigned int offset,
    const unsigned int size
)
    : text(text), filter(filter), offset(offset), size(size)
{
}

const std::string& Query::getText() const {
    return text;
}

const std::string& Query::getFilter() const {
    return filter;
}

unsigned int Query::getOffset() const {
    return offset;
}

unsigned int Query::getSize() const {
    return size;
}

}