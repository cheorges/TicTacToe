#ifndef TICTACTOE_FIELD_H
#define TICTACTOE_FIELD_H


#include "coordinate.h"
#include "../globals/token.h"


class Field {
private:
    Token field[3][3];

    bool isSetPossible(Coordinate coordinate);
public:
    Field();

    Token get(Coordinate coordinate);
    bool set(Coordinate coordinate, Token token);

    void clear();
};


#endif
