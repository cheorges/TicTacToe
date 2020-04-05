#include "field.h"


Field::Field() {
    clear();
}

void Field::clear() {
    for(auto i = 0; i < 3; i++) {
        for(auto j = 0; j < 3; j++) {
            field[i][j] = CLEAN;
        }
    }
}

Token Field::get(Coordinate coordinate) {
    return field[coordinate.x][coordinate.y];
}

bool Field::isSetPossible(Coordinate coordinate) {
    return field[coordinate.x][coordinate.y] == CLEAN;
}

bool Field::set(Coordinate coordinate, Token token) {
    if (isSetPossible(coordinate)) {
        field[coordinate.x][coordinate.y] = token;
        return true;
    }
    return false;
}
