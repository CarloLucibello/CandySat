#include "board.h"

/*

→  : dir=1
↑  : dir=2
←  : dir=3
↓  : dir=4
 
*/


/*********************
 definition restituisce 0 se individua una tripletta
*********************/

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

/*********************
 swap controlla che si possa fare lo swap, ed aventulmente lo fa
*********************/


int Game::swap(int x, int y, int dir){
    
    Candy C=B_app.grid[x][y];
    Candy C_to_swap;
    
    int r=check(x,y,dir);
    
    if (r==0) return 0;
    else{
        if (dir==1){
            C_to_swap=B_app.grid[x+1][y];
            B_app.grid[x][y]=C_to_swap;
            B_app.grid[x+1][y]=C;
        }
        
        if (dir==2){
            C_to_swap=B_app.grid[x][y+1];
            B_app.grid[x][y]=C_to_swap;
            B_app.grid[x][y+1]=C;
        }
        
        if (dir==3){
            C_to_swap=B_app.grid[x-1][y];
            B_app.grid[x][y]=C_to_swap;
            B_app.grid[x-1][y]=C;
        }
        
        if (dir==4){
            C_to_swap=B_app.grid[x+1][y-1];
            B_app.grid[x][y]=C_to_swap;
            B_app.grid[x][y-1]=C;
        }
        
        return 1;
    }
    

    
};

/*********************
 trisat restituisce 1 se le tre caramelle in ingresso sono uguali
*********************/

int Game::trisat(Candy c1, Candy c2, Candy c3){
    if ( (c1 == c2) && (c2 == c3) )
        return 1;
    else return 0;
}

/*********************
 check restituisce 1 se si può fare lo swap
 *********************/

int Game::check(int x, int y, int dir){
    
    Candy C1=B_app.grid[x][y];
    Candy C2;
    
    int flag1, flag2, flag3, flag4, flag5, flag6, flag7, flag8;
    
    // per ogni direzione, bisogna controllare che si può fare una tripletta sia
    // con la caramella che stiamo spostando, sia con quella che viene spostata.
    // in ognuno dei due casi, bisogna fare 4 controlli
    
    if (dir==1){
        
        C2=B_app.grid[x+1][y];
    
        //check sulla caramella che spostiamo
        
        Candy C_tmp1=B_app.grid[x+2][y];
        Candy C_tmp2=B_app.grid[x+3][y];
        
        flag1=trisat(C1, C_tmp1, C_tmp2);
        
        Candy C_tmp3=B_app.grid[x+1][y+1];
        Candy C_tmp4=B_app.grid[x+1][y+2];
        
        flag2=trisat(C1, C_tmp3, C_tmp4);
        
        Candy C_tmp5=B_app.grid[x+1][y-1];
        Candy C_tmp6=B_app.grid[x+1][y-2];
        
        flag3=trisat(C1, C_tmp5, C_tmp6);
        
        Candy C_tmp7=B_app.grid[x+1][y+1];
        Candy C_tmp8=B_app.grid[x+1][y-1];
        
        flag4=trisat(C_tmp7, C1, C_tmp8);
        
        /*---------------*/
        
        //check sulla caramella che viene spostata
        
        Candy C_tmp9=B_app.grid[x-1][y];
        Candy C_tmp10=B_app.grid[x-1][y];
        
        flag5=trisat(C2, C_tmp9, C_tmp10);
        
        Candy C_tmp11=B_app.grid[x][y+1];
        Candy C_tmp12=B_app.grid[x][y+2];
        
        flag6=trisat(C2, C_tmp11, C_tmp12);
        
        Candy C_tmp13=B_app.grid[x][y-1];
        Candy C_tmp14=B_app.grid[x][y-2];
        
        flag7=trisat(C2, C_tmp13, C_tmp14);
        
        Candy C_tmp15=B_app.grid[x][y+1];
        Candy C_tmp16=B_app.grid[x][y-1];
        
        flag8=trisat(C_tmp15, C2, C_tmp16);

    }
    
    if (dir==2) {
        
        C2=B_app.grid[x][y+1];
        
        Candy C_tmp1=B_app.grid[x+1][y+1];
        Candy C_tmp2=B_app.grid[x+2][y+1];
        
        flag1=trisat(C1, C_tmp1, C_tmp2);
        
        Candy C_tmp3=B_app.grid[x][y+2];
        Candy C_tmp4=B_app.grid[x][y+3];
        
        flag2=trisat(C1, C_tmp3, C_tmp4);
        
        Candy C_tmp5=B_app.grid[x-1][y+1];
        Candy C_tmp6=B_app.grid[x-2][y+1];
        
        flag3=trisat(C1, C_tmp5, C_tmp6);
        
        Candy C_tmp7=B_app.grid[x+1][y+1];
        Candy C_tmp8=B_app.grid[x-1][y+1];
        
        flag4=trisat(C_tmp7, C1, C_tmp8);
        
        /*---------------*/
        
        Candy C_tmp9=B_app.grid[x+1][y];
        Candy C_tmp10=B_app.grid[x+2][y];
        
        flag5=trisat(C2, C_tmp9, C_tmp10);
        
        Candy C_tmp11=B_app.grid[x][y-1];
        Candy C_tmp12=B_app.grid[x][y-2];
        
        flag6=trisat(C2, C_tmp11, C_tmp12);
        
        Candy C_tmp13=B_app.grid[x-1][y];
        Candy C_tmp14=B_app.grid[x-2][y];
        
        flag7=trisat(C2, C_tmp13, C_tmp14);
        
        Candy C_tmp15=B_app.grid[x-1][y];
        Candy C_tmp16=B_app.grid[x+1][y];
        
        flag8=trisat(C_tmp15, C2, C_tmp16);
        
        
    }
    
    /* da fare gli altri due casi */
    if (dir==3) C2=B_app.grid[x-1][y];
    if (dir==4) C2=B_app.grid[x][y-1];

    int r=flag1*flag2*flag3*flag4*flag5*flag6*flag7*flag8;
    
    return r;
    
};

/*********************
 search_figure cerca
*********************/

void Game::search_figures(){
    int flag=1;
    int i, j, l=0;
    
    while(flag && l<B_app.size){
        
        i=l%B_app.w;
        j=l/B_app.h;
        
        for (int dir=0; dir<4; ++dir){
            // da fare il check al bordo
            Triplet tri(B_app, dir);
            flag=tri.definition(i, j);
        }
        
        l++;
    }
    
    //una volta trovata la tripletta, eliminala e aggiorna il quadro
    
};


void Game::game_flow(){
    
    int count=0;
    
    // estrai random un punto x,y e una direzione
    // fai per un certo numero di mosse la seguente cosa:
    
    int p=swap(x,y,dir);
    if (p==1){
        search_figures();
    }
    count++;
    
    return;
};
