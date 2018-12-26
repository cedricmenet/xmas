#ifndef BOARD_H
#define BOARD_H


struct Pos{
    char x;
    char y;
};

//objectif
struct obj{
    char type;
    Pos pos;//position of the item
};


struct board{
    static char univ[];
    static char univ_obj[];
    static char univ_length;
    static char board_x_s;
    static char board_y_s;
    static char board_s;//the board size x*y

    char *board;
    Pos p1,
        p2;

    char p1_tile;
    char p2_tile;

    obj* objs_p1;
    obj* objs_p2;

    char objs_p1_s;
    char objs_p2_s;

    char objs_p1_active[3];
    char objs_p2_active[3];

};

struct my_move{
    char id;
    bool line;
    bool reverse;

    static my_move moves[];
    static unsigned int move_s;
    static my_move reverse_f(my_move a) ;
};





#endif // BOARD_H
