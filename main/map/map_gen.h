#ifndef MAP_GEN_H
#define MAP_GEN_H

#include <vector>


#include "board.h"


class map_cache;
class map_gen
{
public:

    static long long constructor_calls;
    static long long  copy_calls;

    static long long negamax_count;
    static long long negamax_inCache;



    map_gen();
    map_gen(const map_gen& cp);
    void map_gen_rand();

    void apply_move(const my_move &m, bool p1);
    static void test_apply_move();

    void display() const ;

    bool operator==(const map_gen&a) const ;

    std::size_t getHast() const;

    static int negaMax(map_gen& node, int depth, int alpha, int beta, char color);
    static int negaMaxCache(map_cache& cache, map_gen& node, int depth, int alpha, int beta, char color);


    board getBoard() const;

private :
    board m_b;

};




#endif // MAP_GEN_H
