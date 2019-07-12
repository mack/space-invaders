//
//  board.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "board.hpp"
#include <unistd.h>

#define WIDTH 36
#define HEIGHT 20

#define WALL '|'
#define FLOOR '-'
#define BLANK ' '
#define ALIEN 'A'
#define PLAYER 'O'
#define MISSILE '^'

Board::Board(): Board(WIDTH, HEIGHT) {}

Board::Board(int width, int height): _width(width), _height(height) {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    window = newwin(height, width, 1, 1);
}

Board::~Board() {
    endwin();
}

int Board::getHeight() {
    // - 1 because of the border
    return _height - 1;
}

int Board::getWidth() {
    // - 1 because of the border
    return _width - 1;
}

// draw the initial board
void Board::update() {
    wclear(window);
    box(window, WALL, FLOOR);
    for (int i = 0; i < gameObjects.size(); i++) {
        Entity* obj = gameObjects.at(i);
        mvwaddch(window, obj->getPos()[1], obj->getPos()[0], PLAYER);
    }
    wrefresh(window);
}

int Board::getInput() {
    wtimeout(window, 200);
    return wgetch(window);
}

void Board::addObject(Entity* object) {
    gameObjects.push_back(object);
}