#include <QtTest>
#include <iostream>
#include <chrono>
#include "map_gen.h"
#include "map_cache.h"
#include "board.h"

using namespace std;

int main(){


    map_gen map;
    map.map_gen_rand();

    map_gen::test_apply_move();

    map_cache mCache;

   std::unordered_map<map_gen, int, MyHash>::const_iterator it;
   int count =0;


   auto start = std::chrono::high_resolution_clock::now();
   int in_cache = 0;
    for(long i = 0; i < 50000;i++ )
    {

        //cout << i << endl;
        map.map_gen_rand();

        it = mCache.map().find(map);


        if(it != mCache.map().end())
        {
            if(!(  map == it->first )){
                cout << "collision" << MyHash{}(it->first) << " " << MyHash{}(map);
                it->first.display();
                map.display();
            }
            else{
                in_cache++;

                /*cout << "*******" << endl;
                it->first.display();
                map.display();*/
            }
        }
        else{
            count ++;
            mCache.map().insert(std::pair<map_gen&,int>(map,1));

        }

        //

    }
    cout << "found in cache "<< in_cache << endl;

    auto finish = std::chrono::high_resolution_clock::now();

    auto start_a = std::chrono::high_resolution_clock::now();
    for(long i = 0; i < 30000;i++ )
    {
        //map.map_gen_rand();
    }
    auto finish_a = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish_a-start_a).count() << "us\n";




    std::cout << std::chrono::duration_cast<std::chrono::seconds>(finish-start).count() << "s";

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count()%1000 << "ms";

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count()%1000 << "us";

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()%1000 << "ns\n";

    cout << "count "<< count << endl;
    cout << map_gen::constructor_calls <<" " << map_gen::copy_calls << endl;


    //negamax




    auto start_b = std::chrono::high_resolution_clock::now();

    map_gen::negaMax(map,5,INT_MIN,INT_MAX,1);

    auto finish_b = std::chrono::high_resolution_clock::now();
    std::cout << "negamax in " <<  std::chrono::duration_cast<std::chrono::microseconds>(finish_b-start_b).count() << "us\n"
              << "for " << map_gen::negamax_count << endl
              << "perf " << map_gen::negamax_count / (std::chrono::duration_cast<std::chrono::microseconds>(finish_b-start_b).count()+1)
              <<  " MegaNeg/sec" << endl;



    map_gen::negamax_count = 0;

    auto start_c = std::chrono::high_resolution_clock::now();
    map_gen map2;
    map2.map_gen_rand();
    map_cache Cache;
    map_gen::negaMaxCache(Cache,map2,13,INT_MIN,INT_MAX,1);

    auto finish_d = std::chrono::high_resolution_clock::now();
    std::cout << "negamax in " <<  std::chrono::duration_cast<std::chrono::microseconds>(finish_d-start_c).count() << " us\n"
              << "for " << map_gen::negamax_count << "in cache " << map_gen::negamax_inCache <<  endl
              << "perf " << map_gen::negamax_count / (std::chrono::duration_cast<std::chrono::microseconds>(finish_d-start_c).count()+1.)
              <<  " MegaCacheNeg/sec"
               << endl
               << "cache size " << Cache.map().size()
               << endl;


    cout << "          ******         " << endl;
    auto start_e = std::chrono::high_resolution_clock::now();

    map2.map_gen_rand();

    map_gen::negaMaxCache(Cache,map2,13,INT_MIN,INT_MAX,1);

    auto finish_e = std::chrono::high_resolution_clock::now();
    std::cout << "negamax in " <<  std::chrono::duration_cast<std::chrono::microseconds>(finish_e-start_e).count() << " us\n"
              << "for " << map_gen::negamax_count << "in cache " << map_gen::negamax_inCache <<  endl
              << "perf " << map_gen::negamax_count / (std::chrono::duration_cast<std::chrono::microseconds>(finish_e-start_e).count()+1.)
              <<  " MegaCacheNeg/sec"
               << endl
               << "cache size " << Cache.map().size()
               << endl;
    cout << "          ******         " << endl;
    auto start_f = std::chrono::high_resolution_clock::now();

    map2.map_gen_rand();

    map_gen::negaMaxCache(Cache,map2,13,INT_MIN,INT_MAX,1);

    auto finish_f = std::chrono::high_resolution_clock::now();
    std::cout << "negamax in " <<  std::chrono::duration_cast<std::chrono::microseconds>(finish_f-start_f).count() << " us\n"
              << "for " << map_gen::negamax_count << "in cache " << map_gen::negamax_inCache <<  endl
              << "perf " << map_gen::negamax_count / (std::chrono::duration_cast<std::chrono::microseconds>(finish_f-start_f).count()+1.)
              <<  " MegaCacheNeg/sec"
               << endl
               << "cache size " << Cache.map().size()
               << endl;





    return  0;
}
