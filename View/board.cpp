//
//  board.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "board.hpp"
#include <iostream>
#include <curses.h>


#define WIDTH 100
#define HEIGHT 100

#define WALL "|"
#define FLOOR "-"
#define BLANK " "
#define ALIEN "A"
#define SPACESHIP "O"
#define MISSILE "^"

Board::Board() {}

Board::Board(int width, int height): width(width), height(height) {}

// draw the initial board
void Board::setup() {
//    WINDOW *menu_win;
//
//    int highlight = 1;
//    int choice = 0;
//    int c;
//
//    initscr();
//    clear();
//    noecho();
//    cbreak();
//    startx = (80 - WIDTH) / 2;
//    starty = (24 - HEIGHT) / 2;
//
//    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
//    keypad(menu_win, TRUE);
//    mvprintw(5, 27, "Welcome to SPACE INVADERS.");
//    refresh();
    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++) {
            // draw the top
            if (y == 0 && x < width) std::cout << FLOOR;
            else if (y == 0 && x == width) std::cout << FLOOR << std::endl;
            else if (x == 0 && y != height) std::cout << WALL;
            else if (x == width && y != height) std::cout << WALL << std::endl;
            else if (y == height) std::cout << FLOOR;
            else std::cout << BLANK;
        }
    }
    std::cout << std::endl;
}
