#ifndef CANDY_H
#define CANDY_H

enum CandyType {BLUE, RED, GREEN};

class Candy{
public:
    CandyType type;

    Candy() {}
    
    inline bool operator==(Candy C){
        if ((this->type)==(C.type)) return 1;
        else return 0;
    }
    
    virtual ~Candy() {}
};





#endif // CANDY_H
