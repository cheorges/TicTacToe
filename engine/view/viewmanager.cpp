#include <curses.h>
#include "viewmanager.h"


using namespace std;

ViewManager::ViewManager() {
    initscr();
    noecho();
    getmaxyx(stdscr, _Y, _X);
    raw();

    for(int i = 0; i < 2; i++) {
        cursorPosition[i] = 1;
    }
}

ViewManager::~ViewManager() {
    endwin();
}

void ViewManager::clearGameOverInfo() {
    mvprintw(_Y / 2, _X / 2 - 28, "            ");
    mvprintw(_Y - 6, 1, "              ");
}

void ViewManager::printMap(Game game) {
    mvprintw(_Y / 2 - 7, _X / 2 - 11, "+-----+-----+-----+");
    mvprintw(_Y / 2 - 6, _X / 2 - 11, "|     |     |     |");
    mvprintw(_Y / 2 - 5, _X / 2 - 11, "|  %c  |  %c  |  %c  |",
             game.getTokenAt(Coordinate(0, 0)),
             game.getTokenAt(Coordinate(0, 1)),
             game.getTokenAt(Coordinate(0, 2)));
    mvprintw(_Y / 2 - 4, _X / 2 - 11, "|     |     |     |");
    mvprintw(_Y / 2 - 3, _X / 2 - 11, "+-----+-----+-----+");
    mvprintw(_Y / 2 - 2, _X / 2 - 11, "|     |     |     |");
    mvprintw(_Y / 2 - 1, _X / 2 - 11, "|  %c  |  %c  |  %c  |",
             game.getTokenAt(Coordinate(1, 0)),
             game.getTokenAt(Coordinate(1, 1)),
             game.getTokenAt(Coordinate(1, 2)));
    mvprintw(_Y / 2 - 0, _X / 2 - 11, "|     |     |     |");
    mvprintw(_Y / 2 + 1, _X / 2 - 11, "+-----+-----+-----+");
    mvprintw(_Y / 2 + 2, _X / 2 - 11, "|     |     |     |");
    mvprintw(_Y / 2 + 3, _X / 2 - 11, "|  %c  |  %c  |  %c  |",
             game.getTokenAt(Coordinate(2, 0)),
             game.getTokenAt(Coordinate(2, 1)),
             game.getTokenAt(Coordinate(2, 2)));
    mvprintw(_Y / 2 + 4, _X / 2 - 11, "|     |     |     |");
    mvprintw(_Y / 2 + 5, _X / 2 - 11, "+-----+-----+-----+");

    goToCurrentPosition();
}

void ViewManager::printStatus(Game game) {
    mvprintw(_Y / 2 - 10, _X / 2 - 28, "Current Player: %c", game.getActivePlayerRepresentation());
    mvprintw(_Y / 2 - 6, _X / 2 - 28, "Player X: %i", game.getScorePlayerX());
    mvprintw(_Y / 2 - 4, _X / 2 - 28, "Player O: %i", game.getScorePlayerO());
    goToCurrentPosition();
}

void ViewManager::printInformation() {
    mvprintw(_Y - 5, 1, "Set [ ENTER ]");
    mvprintw(_Y - 4, 1, "Move [ LEFT | RIGHT | UP | DOWN ]");
    mvprintw(_Y - 3, 1, "Quit [ Q ]");
}

void ViewManager::goToCurrentPosition() {
    move(_Y / 2 - 5 + cursorPosition[0] * 4, _X / 2 - 8 + cursorPosition[1] * 6);
}

void ViewManager::updatePosition(Key key) {
    if(key == LEFT && cursorPosition[1] > 0) {
        cursorPosition[1]--;
    } else if (key == RIGHT && cursorPosition[1] < 2) {
        cursorPosition[1]++;
    } else if (key == UP && cursorPosition[0] > 0) {
        cursorPosition[0]--;
    } else if (key == DOWN && cursorPosition[0] < 2) {
        cursorPosition[0]++;
    }
}

void ViewManager::printGameOverInfo(Game game, GameState gameState) {
    if (gameState == FINISH_WIN) {
        mvprintw(_Y / 2, _X / 2 - 28, "Winner is %c", game.getActivePlayerRepresentation());
    } else {
        mvprintw(_Y / 2, _X / 2 - 28, "Tie");
    }
    mvprintw(_Y - 6, 1, "New Game [ Y ]");
}

void ViewManager::refresh(Game game) {
    printInformation();
    clearGameOverInfo();
    printMap(game);
    printStatus(game);
}

Coordinate ViewManager::getCursorPosition() {
    return Coordinate(cursorPosition[0], cursorPosition[1]);
}

Key ViewManager::getInput() {
    char key = getch();
    return static_cast<Key>(key);
}