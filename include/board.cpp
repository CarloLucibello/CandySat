#include "board.h"

int Triplet::definition(int x, int y){
    t[0]=B_app.grid[x][y];
    
    if (dir==1){
        t[1]=B_app.grid[x+1][y];
        t[2]=B_app.grid[x+2][y];
    }
    if (dir==2){
        t[1]=B_app.grid[x][y+1];
        t[2]=B_app.grid[x][y+2];
    }
    if (dir==3){
        t[1]=B_app.grid[x-1][y];
        t[2]=B_app.grid[x-2][y];
    }
    if (dir==4){
        t[1]=B_app.grid[x][y-1];
        t[2]=B_app.grid[x][y-2];
    }
    
    if ((t[0]==t[1]) && (t[1]==t[2]))
        return 0;
    else return 1;
    
};
