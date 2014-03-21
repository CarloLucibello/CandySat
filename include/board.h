#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cassert>

using namespace std;

#include "candy.h"

/**********************
/* La classe che rappresenta un quadro di gioco
***********/
class Board{
public:
        int w;  // width
        int h;  // height of the visible part
        int hS;   // height of the whole strip
        vector<vector<Candy>> grid;  // the baord matrix

        Board() {}

        Board(int width, int height, int heightStrip)
            : w(width), h(height), hS(heightStrip)  {
            assert(h <= hS);
            grid.resize(hS);
            for(auto& row : grid){
                row.resize(w);
            }
        }

        virtual ~Board() {}
};

#endif // BOARD_H
