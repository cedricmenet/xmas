#ifndef MYHASH_H
#define MYHASH_H

#include <functional>

#include "map_gen.h"

struct MyHash
{
public:

    std::size_t operator()(map_gen const& m) const noexcept;
};

#endif // MYHASH_H
