#ifndef TICTACTOE_VIEWMANAGER_H
#define TICTACTOE_VIEWMANAGER_H

#include <map>
#include <string>
#include "../objects/field.h"
#include "../globals/gamestate.h"
#include "../globals/key.h"
#include "../objects/game.h"

using namespace std;

class ViewManager {
private:
    int _X, _Y;
    int cursorPosition[2];

    void printMap(Game game);
    void clearGameOverInfo();
    void printStatus(Game game);
    void goToCurrentPosition();
    void printInformation();
public:
    ViewManager();
    ~ViewManager();

    void updatePosition(Key key);
    void printGameOverInfo(Game game, GameState state);
    void refresh(Game game);

    Coordinate getCursorPosition();
    Key getInput();
};

#endif
