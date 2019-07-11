//
//  board.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "board.hpp"
#include <unistd.h>

#define WIDTH 35
#define HEIGHT 20

#define WALL '|'
#define FLOOR '-'
#define BLANK ' '
#define ALIEN 'A'
#define PLAYER 'O'
#define MISSILE '^'

Board::Board(): Board(WIDTH, HEIGHT) {}

Board::Board(int width, int height): _width(width), _height(height), pos(1) {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    window = newwin(height, width, 1, 1);
    missilePos = 17;

}

Board::~Board() {
    endwin();
}

// draw the initial board
void Board::update() {

      while (true) {
          // TODO: Seperate out this a bit into main.cpp
          // this was just for trying to get it to work
        box(window, WALL, FLOOR);
        mvwaddch(window, 18, pos, PLAYER);
        mvwaddch(window, missilePos, pos, BLANK);
        missilePos -= 1;
        mvwaddch(window, missilePos, pos, MISSILE);
        wrefresh(window);
        wtimeout(window, 200);
        int c = wgetch(window);

        switch(c) { // the real value
            case 'C':
                if (pos + 1 >= 1 || pos + 1 <= _width)
                mvwaddch(window, 18, pos, BLANK);
                mvwaddch(window, missilePos, pos, BLANK);
                pos += 1;
                break;
            case 'D':
                    if (pos - 1 >= 1 || pos - 1 <= _width)
                    mvwaddch(window, 18, pos, BLANK);
                    mvwaddch(window, missilePos, pos, BLANK);
                    pos -= 1;
                break;
            case 'A':
                missilePos = 17;
        }
    }
    
}

void Board::movePlayer(int newX) {
    if (pos + newX >= 1 || pos + newX <= _width)
    mvwaddch(window, 18, pos, BLANK);
    mvwaddch(window, missilePos, pos, BLANK);
    pos += newX;
}