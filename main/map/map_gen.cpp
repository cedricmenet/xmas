#include <iostream>
#include <cstdlib>
#include <iomanip>


#include "map_gen.h"
#include "map_cache.h"

using namespace std;


long long map_gen::constructor_calls =0;
long long  map_gen::copy_calls = 0;
long long  map_gen::negamax_count = 0;
long long map_gen::negamax_inCache = 0;


map_gen::map_gen()
{
    map_gen::constructor_calls++;

}

map_gen::map_gen(const map_gen &cp)
{
    map_gen::copy_calls++;

    m_b.board = new char[board::board_s];
    for (unsigned char i = 0; i < board::board_s ; i++)
    {
        m_b.board[i] = cp.m_b.board[i];

    }

    m_b.p1 = cp.m_b.p1;
    m_b.p2 = cp.m_b.p2;

    m_b.p1_tile = cp.m_b.p1_tile;
    m_b.p2_tile = cp.m_b.p2_tile;

    m_b.objs_p1 = new obj[cp.m_b.objs_p1_s];
    for(int i =0; i < cp.m_b.objs_p1_s;i++)
    {
        m_b.objs_p1[i] = cp.m_b.objs_p1[i];
    }

    m_b.objs_p2 = new obj[cp.m_b.objs_p2_s];
    for(int i =0; i < cp.m_b.objs_p2_s;i++)
    {
        m_b.objs_p2[i] = cp.m_b.objs_p2[i];
    }


    for(int i =0; i < 3;i++)
    {
        m_b.objs_p1_active[i] = cp.m_b.objs_p1_active[i];
    }
    for(int i =0; i < 3;i++)
    {
        m_b.objs_p2_active[i] = cp.m_b.objs_p2_active[i];
    }


}

void map_gen::map_gen_rand()
{
    //init all datas of board
    m_b.board = new char[board::board_s];

    for (unsigned char i = 0; i < board::board_s; i++)
    {
        m_b.board[i] = board::univ[rand()%board::univ_length];

    }

    m_b.p1 = {2,2};
    m_b.p2 = {2,2};

    m_b.p1_tile = board::univ[0];
    m_b.p2_tile = board::univ[0];

    m_b.objs_p1 = new obj[3];
    m_b.objs_p1[0] = {0,{4,4}};
    m_b.objs_p1[1] = {1,{5,5}};
    m_b.objs_p1[2] = {2,{3,3}};
    m_b.objs_p1_s = 3;

    m_b.objs_p2 = new obj[3];
    m_b.objs_p2[0] = {0,{4,4}};
    m_b.objs_p2[1] = {1,{5,5}};
    m_b.objs_p2[2] = {2,{3,3}};
    m_b.objs_p2_s = 3;

    m_b.objs_p1_active[0] = 0;
    m_b.objs_p1_active[1] = 1;
    m_b.objs_p1_active[2] = 2;

    m_b.objs_p2_active[0] = 0;
    m_b.objs_p2_active[1] = 1;
    m_b.objs_p2_active[2] = 2;


}

void map_gen::apply_move(const my_move &m,bool p1)
{
    char p_tile;
    if(p1)
        p_tile = m_b.p1_tile;
    else
        p_tile = m_b.p2_tile;

    if(m.line){
        if(!m.reverse)
        {
            unsigned char start = m.id*board::board_y_s;
            int tmp_tile = m_b.board[board::board_x_s+start-1];
            for(char i =board::board_x_s+start-1  ; i > start;--i){
                m_b.board[i]=m_b.board[i-1];
            }
            m_b.board[start] = p_tile;
            p_tile = tmp_tile;
        }
        else{
            unsigned char start = m.id*board::board_y_s;
            int tmp_tile = m_b.board[start];
            for(char i = start ; i <  board::board_x_s+start-1;++i){
                m_b.board[i]=m_b.board[i+1];
            }
            m_b.board[board::board_x_s+start-1] = p_tile;
            p_tile = tmp_tile;
        }


    }
    else{
        if(!m.reverse)
        {
            unsigned char start = m.id;
            int tmp_tile = m_b.board[(board::board_y_s-1)*board::board_x_s+start];
            for(char i =board::board_y_s-1  ; i > 0;--i){
                m_b.board[i*board::board_x_s+start]=m_b.board[(i-1)*board::board_x_s+start];
            }
            m_b.board[start] = p_tile;
            p_tile = tmp_tile;
        }
        else{

            unsigned char start = m.id;
            int tmp_tile = m_b.board[start];
            for(char i =0  ; i < board::board_y_s-1;++i){
                m_b.board[i*board::board_x_s+start]=m_b.board[(i+1)*board::board_x_s+start];
            }
            m_b.board[(board::board_y_s-1)*board::board_x_s+start] = p_tile;
            p_tile = tmp_tile;
        }
    }


    if(p1)
        m_b.p1_tile = p_tile ;
    else
        m_b.p2_tile = p_tile;

}

void map_gen::test_apply_move()
{

    for(int i = 0; i < 10000;i++)
    {
        map_gen m1;

        m1.map_gen_rand();
        map_gen m2(m1);
        my_move move = my_move::moves[rand()%my_move::move_s];

        /*cout << "test0" << endl;
        m1.display();*/
        m1.apply_move(move,true);
        /*cout << "test1" << endl;;
        m1.display();
        cout << "test2" << endl;*/

        my_move move_rev = my_move::reverse_f(move);



        m1.apply_move(move_rev,true);
       /* m1.display();
        cout << "test3" << endl;*/

        if(!(m1 ==m2))
            cout << "failled";




    }
}


void map_gen::display() const
{

    for(int i = 0; i < board::board_s; i++)
    {
        if(i%board::board_x_s == 0 && i!=0)
            cout << endl;
        cout <<setw(3) <<  static_cast<int>(m_b.board[i])<<' ';

    }
    cout << endl;
}

bool map_gen::operator==(const map_gen &a) const
{



    for(unsigned char i = 0; i < board::board_s; i++)
    {
        if (m_b.board[i] != a.m_b.board[i])
            return false;
    }
    return true;
}





size_t map_gen::getHast() const
{
    size_t ret =0;
    for(char i = 0; i < board::board_s;i++)
    {
        ret = ret ^ ((m_b.board[i] << i));
    }
    return ret;
}

int map_gen::negaMax(map_gen &node, int depth, int alpha, int beta, char color)
{
    map_gen::negamax_count++;
    if(depth <= 0)
        return color*rand()%10;

    int value = INT_MIN;

    for(unsigned i = 0; i < my_move::move_s;++i)
    {
        node.apply_move(my_move::moves[i],color);
        value = max(value , map_gen::negaMax(node,depth-1,-beta,-alpha,-color));
        node.apply_move(my_move::reverse_f(my_move::moves[i]),color);
        alpha = max(alpha,value);
        if(alpha>beta)
            break;
    }
    return value;
}
int map_gen::negaMaxCache(map_cache& cache, map_gen &node, int depth, int alpha, int beta, char color)
{
    map_gen::negamax_count++;


    if(cache.map().find(node) != cache.map().end() ){
        map_gen::negamax_inCache++;
        return color*rand()%10;
    }

    if(depth <= 0)
        return color*rand()%10;

    int value = INT_MIN;

    for(unsigned i = 0; i < my_move::move_s;++i)
    {
        node.apply_move(my_move::moves[i],color);
        value = max(value , map_gen::negaMaxCache(cache,node,depth-1,-beta,-alpha,-color));
        node.apply_move(my_move::reverse_f(my_move::moves[i]),color);
        alpha = max(alpha,value);
        if(alpha>beta){

            break;
        }
    }
    cache.map().insert(std::pair<map_gen&,int>(node,value));

    return value;
}
