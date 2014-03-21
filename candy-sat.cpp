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
    
    search_figure(B);
    
    cout << "Hello world!" << endl;
    return 0;
}


void search_figure(Board B){
    int flag=1;
    int i, j, l=0;
    
    while(flag && l<B.size){
    
        i=l%B.w;
        j=l/B.h;
        
        for (int dir=0; dir<4; ++dir){
            // da fare il check al bordo
            // oppure ci inventiamo Candy Crush con le condizioni periodiche al bordo ?!?
            Triplet tri(B, dir);
            flag=tri.definition(i, j);
        }
        
        l++;
    }
    
}
