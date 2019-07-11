//
//  board.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "board.hpp"


#define WIDTH 35
#define HEIGHT 20

#define WALL '|'
#define FLOOR '-'
#define BLANK ' '
#define ALIEN "A"
#define SPACESHIP "O"
#define MISSILE "^"

Board::Board(): Board(WIDTH, HEIGHT) {}

Board::Board(int width, int height): _width(width), _height(height), pos(1) {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    window = newwin(height, width, 1, 1);
}

Board::~Board() {
    endwin();
}

// draw the initial board
void Board::update() {
        box(window, WALL, FLOOR);
        mvwaddch(window, 18, pos, 'O');
        wrefresh(window);
}

void Board::movePlayer(int newX) {
    if (pos + newX >= 1 || pos + newX <= _width)
    mvwaddch(window, 18, pos, BLANK);
    pos += newX;
}