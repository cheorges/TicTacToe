#include "game.h"


int Game::getScorePlayerX() {
    return playerX.getScore();
}

int Game::getScorePlayerO() {
    return playerO.getScore();
}

Token Game::getActivePlayerRepresentation() {
    return activePlayer->getToken();
}

GameState Game::setTokenAt(Coordinate coordinate) {
    GameState gameState = GAME_RUNNING;
    if (field.set(coordinate, activePlayer->getToken())) {
        turn++;
        gameState = hasActivePlayerWin();
        if (gameState == FINISH_WIN) {
            return gameState;
        }
    }

    changeActivePlayer();
    return GAME_RUNNING;
}

Token Game::getTokenAt(Coordinate coordinate) {
    return field.get(coordinate);
}

GameState Game::hasActivePlayerWin() {
    if(field.get(Coordinate(0, 0)) == activePlayer->getToken()
       && field.get(Coordinate(1, 1)) == activePlayer->getToken()
       && field.get(Coordinate(2,2)) == activePlayer->getToken()) {
        activePlayer->win();
        return FINISH_WIN;
    }
    if(field.get(Coordinate(0,2)) == activePlayer->getToken()
       && field.get(Coordinate(1,1)) == activePlayer->getToken()
       && field.get(Coordinate(2,0)) == activePlayer->getToken()) {
        activePlayer->win();
        return FINISH_WIN;
    }
    for(int it = 0; it < 3; it++) {
        if((field.get(Coordinate(it, 0)) == activePlayer->getToken()
            && field.get(Coordinate(it, 1)) == activePlayer->getToken()
            && field.get(Coordinate(it, 2)) == activePlayer->getToken())
           ||
           (field.get(Coordinate(0, it)) == activePlayer->getToken()
            && field.get(Coordinate(1, it)) == activePlayer->getToken()
            && field.get(Coordinate(2, it)) == activePlayer->getToken())) {
            activePlayer->win();
            return FINISH_WIN;
        }
    }

    if (turn == 9) {
        return FINISH_TIE;
    }

    return GAME_RUNNING;
}


void Game::init() {
    field.clear();
}

void Game::changeActivePlayer() {
    playerX.toggleActive();
    playerO.toggleActive();
    activePlayer = playerX.isActive() ? &playerX : &playerO;
}
