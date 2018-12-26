#include "map_cache.h"
#include "myhash.h"

map_cache::map_cache() : m_map( )
{

}

std::unordered_map<map_gen, int, MyHash>& map_cache::map()
{
    return m_map;
}

