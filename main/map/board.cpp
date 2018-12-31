#include "board.h"


char board::univ[] = {3,5,6,7,9,10,11,12,13,14,15};
//char board::univ[] = {3,5};
char board::univ_obj[] = {'0','1','2','3','4'};
char board::univ_length = sizeof (board::univ)/sizeof (board::univ[0]);
char board::univ_obj_length = sizeof (board::univ_obj)/sizeof (board::univ_obj[0]);

char board::board_x_s = 7;
char board::board_y_s = 7;
char board::board_s = board::board_x_s*board::board_y_s;


unsigned int my_move::move_s = 28;
my_move my_move::moves[] = {{0,0,0},
                      {1,0,0},
                      {2,0,0},
                      {3,0,0},
                      {4,0,0},
                      {5,0,0},
                      {6,0,0},

                      {0,1,0},
                      {1,1,0},
                      {2,1,0},
                      {3,1,0},
                      {4,1,0},
                      {5,1,0},
                      {6,1,0},

                      {0,0,1},
                      {1,0,1},
                      {2,0,1},
                      {3,0,1},
                      {4,0,1},
                      {5,0,1},
                      {6,0,1},

                      {0,1,1},
                      {1,1,1},
                      {2,1,1},
                      {3,1,1},
                      {4,1,1},
                      {5,1,1},
                      {6,1,1},
                     };

my_move my_move::reverse_f(my_move a)
{
    return {a.id,a.line,!a.reverse};
}
