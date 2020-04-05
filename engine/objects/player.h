#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H


#include "../globals/token.h"

class Player {
private:
    Token token;
    int score = 0;
    bool active = false;

public:
    Player(Token token, bool active) : token(token), active(active) {};

    int getScore() { return score; }
    bool isActive() { return active; }
    Token getToken() { return token; }

    void win() { score++; }
    void toggleActive() { active = !active; }
};


#endif
