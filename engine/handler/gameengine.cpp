#include "gameengine.h"


using namespace std;

GameEngine::GameEngine(Game game, ViewManager viewManager) {
    this->game = game;
    this->viewManager = viewManager;

    init();
}

void GameEngine::run() {
    loop();
}

void GameEngine::init() {
    gameState = GAME_RUNNING;
    game.init();
    viewManager.refresh(game);
}

void GameEngine::loop() {
    while (gameState != QUIT) {
        while (gameState == GAME_RUNNING) {
            handleInput();
            viewManager.refresh(game);
        }
        viewManager.printGameOverInfo(game, gameState);
        while (gameState == FINISH_WIN || gameState == FINISH_TIE) {
            Key key = viewManager.getInput();
            switch(key) {
                case Y:
                case y:
                    init();
                    break;
                case Q:
                    gameState = QUIT;
                    break;
            }
        }
    }
}

void GameEngine::handleInput() {
    Key key = viewManager.getInput();
    switch(key) {
        case Q:
            gameState = QUIT;
            break;
        case LEFT:
        case RIGHT:
        case UP:
        case DOWN:
            viewManager.updatePosition(key);
            break;
        case ENTER:
            gameState = game.setTokenAt(viewManager.getCursorPosition());
            break;
    }
}