#include "myhash.h"



std::size_t MyHash::operator()(const map_gen &m) const noexcept
{
    return m.getHast();
}
