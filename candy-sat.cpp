#include <iostream>
#include "board.h"
#include "candy.h"

using namespace std;

void search_figure(Board B);

int main()
{
   
    
    int w=9; // width
    int h=9;  // height of the visible part
    int hS=81;   // height of the whole strip

    Board B(w, h, hS);
    
    //qua facciamo giocare il player
    
    //search_figure(B);
    
    cout << "Hello world!" << endl;
    return 0;
}

