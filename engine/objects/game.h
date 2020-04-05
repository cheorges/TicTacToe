#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H


#include "field.h"
#include "player.h"
#include "../globals/token.h"
#include "../globals/gamestate.h"

class Game {
private:
    Field field = Field();
    Player playerX = Player(X, true);
    Player playerO = Player(O, false);
    Player* activePlayer = &playerX;
    int turn = 0;

    GameState hasActivePlayerWin();

    void changeActivePlayer();

public:
    int getScorePlayerX();
    int getScorePlayerO();
    Token getActivePlayerRepresentation();
    Token getTokenAt(Coordinate coordinate);
    GameState setTokenAt(Coordinate coordinate);

    void init();
};


#endif
