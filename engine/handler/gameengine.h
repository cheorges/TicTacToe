#ifndef TICTACTOE_GAMEENGINE_H
#define TICTACTOE_GAMEENGINE_H

#include <map>
#include "../globals/gamestate.h"
#include "../objects/field.h"
#include "../view/viewmanager.h"
#include "../objects/game.h"

using namespace std;

class GameEngine {
private:
    GameState gameState;
    Game game;
    ViewManager viewManager;

    void handleInput();
    void loop();
    void init();

public:
    GameEngine(Game game, ViewManager viewManager);

    void run();
};


#endif
