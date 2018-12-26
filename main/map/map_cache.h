#ifndef MAP_CACHE_H
#define MAP_CACHE_H

#include <unordered_map>
#include <vector>

#include "myhash.h"


class map_cache
{
public:
    map_cache();

    std::unordered_map<map_gen, int, MyHash>& map();


private :
    std::unordered_map<map_gen,int,MyHash> m_map;
};

#endif // MAP_CACHE_H
