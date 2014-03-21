#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cassert>

using namespace std;

#include "candy.h"
// prova modifica

/**********************
La classe che rappresenta un quadro di gioco
**********+++++++++++*/

class Board{
public:
    int w; // width
    int h;  // height of the visible part
    int hS;   // height of the whole strip
    int size; // size of the visible part
    vector<vector<Candy>> grid; // the board matrix

    Board() {}

    Board(int width, int height, int heightStrip)
    : w(width), h(height), hS(heightStrip)  {
        assert(h <= hS);
        grid.resize(hS);
        size=h*w;
        for(auto& row : grid){
            row.resize(w);
        }
    }

    virtual ~Board() {}

};


/**********************
 La classe che rappresenta una figura generica (è virtuale)
 *********************/

class Figure {
public:
    Board B_app;
    Figure(Board B): B_app(B){}
    
    virtual int definition(int x, int y) = 0;    //this makes the class virtual
    
};

/**********************
 La classe che rappresenta una tripletta
 *********************/

class Triplet : public Figure {
    vector<Candy> t;
    int dir;
    
public:
    Triplet(Board B, int p_dir): dir(p_dir), Figure(B){
        t.resize(3);
    }
    
    int definition(int x, int y);
};


    
#endif // BOARD_H
