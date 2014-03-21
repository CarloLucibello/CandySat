#ifndef CANDY_H
#define CANDY_H

enum CandyType {BLUE, RED, GREEN};

class Candy{
public:
    CandyType type;

    Candy() {}

    virtual ~Candy() {}
};

#endif // CANDY_H
