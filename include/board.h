#ifndef BOARD_H
#define BOARD_H

#include "candy.h"

/**********************
/* La classe che rappresenta un quadro di gioco
***********/
class Board{
public:
        int w;  // width
        int h;  // height of the visible part
        int N;   // height of the whole strip

        Board() {}

        virtual ~Board() {}
};

#endif // BOARD_H
