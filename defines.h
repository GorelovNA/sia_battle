#ifndef DEFINES_H
#define DEFINES_H
#include <QString>

/*общее*/
#define FIELD_CELL_HIEGH 35
#define FIELD_CELL_WIDTH 35
#define FIELD_ROWS 10
#define FIELD_COLUMNS 10

/*my field coord*/
#define MY_FIELD_COORD_X 49
#define MY_FIELD_COORD_Y 193

/*enemy field coord*/
#define ENEMY_FIELD_COORD_X 503
#define ENEMY_FIELD_COORD_Y 193

/*TCP/IP*/
//#define HOST_IP "127.0.0.1"
#define HOST_PORT 1234



//enums

enum state{GAME_START=0, SHIPS_PLACED=1, CONNECTED_TO_SERVER=2,W8_CLIENT=3,
           YOU_TURN=4, ENEMY_TURN=5, GAME_OVER=6};


//structs
struct cell_params_struct{
    int row;
    int column;
    int state;
};

#endif // DEFINES_H
