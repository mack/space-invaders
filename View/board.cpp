//
//  board.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "board.hpp"
#include <unistd.h>
#include <math.h>

#define WIDTH 36
#define HEIGHT 20
#define TIMEOUT 25

#define WALL '|'
#define FLOOR '-'

// MARK: - Constructors & Deconstructors

Board::Board(): Board(WIDTH, HEIGHT) {}

Board::Board(int width, int height): _width(width), _height(height) {
    // Initial NCurses setup
    initscr();
    noecho(); // Don't echo input
    cbreak();
    curs_set(0); // Hide blinking cursor
    keypad(stdscr, TRUE); // Accept arrow keys as input
    window = newwin(height, width, 1, 1); // Initialize new ncurses window
}

Board::~Board() {
    endwin();
}

// MARK: - Getters & Setters

int Board::getHeight() {
    return _height - 1;
}

int Board::getWidth() {
    return _width - 1;
}

// MARK: - Board methods

void Board::checkCollision() {
    for (int i = 0; i < gameObjects.size(); i++) {
        for (int j = 0; j < gameObjects.size(); j++) {
            Entity* obj1 = gameObjects.at(i);
            Entity* obj2 = gameObjects.at(j);

            // Verifying Alien/Projectile collision
            if (((obj1->getRepresentation() == 'A' && obj2->getRepresentation() == '^') ||
                  (obj2->getRepresentation() == 'A' && obj1->getRepresentation() == '^')) &&
                  (obj1->getPosX() == obj2->getPosX() && obj1->getPosY() == obj2->getPosY())) {

                gameObjects.erase(gameObjects.begin() + i);
                gameObjects.erase((gameObjects.begin() - 1) + j);
            }
        }
    }
}

void Board::update() {
    // Clear the window and then re-draw
    wclear(window);
    box(window, WALL, FLOOR);
    // Draw all game objects in entity vector
    int alienCount = 0;
    for (int i = 0; i < gameObjects.size(); i++) {
        Entity* obj = gameObjects.at(i);
        if (obj->getRepresentation() == 'A') alienCount++;
        // Print game object
        mvwaddch(window, obj->getPosY(), obj->getPosX(), obj->getRepresentation());
        // Call game objects update function
        obj->update();
    }
    if (alienCount == 0) {
        mvwprintw(window, floor(_height/2), floor(_width/2), "You win!!");
    }
    // Refresh the terminal
    wrefresh(window);
}

int Board::getInput() {
    // Timeout prevents the wgetchar() from blocking
    wtimeout(window, TIMEOUT);
    return wgetch(window);
}

void Board::addObject(Entity* object) {
    gameObjects.push_back(object);
}
