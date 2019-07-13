//
//  Board.cpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#include <unistd.h>
#include <math.h>

#include "Board.hpp"
#include <Alien.hpp>
#include <Constants.hpp>

// MARK: - Constructors & Deconstructors
Board::Board(): Board(DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT) {}

Board::Board(int width, int height): _width(width), _height(height), _message("") {
    // Initial NCurses setup
    initscr();
    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_RED, 1000, 0, 0);
    init_color(COLOR_GREEN, 0, 1000, 0);
    init_color(COLOR_MAGENTA, 1000, 500, 0); // Using magenta as orange, since we only have 8 colors
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
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
void Board::update() {
    // Clear the window and then re-draw
    wclear(window);
    box(window, WALL, FLOOR);

    // Draw all game objects in entity vector
    for (int i = 0; i < gameObjects.size(); i++) {
        Entity* obj = gameObjects.at(i);
        // Check for any collisions
        for (int j = i + 1; j < gameObjects.size(); j++) {
            Entity* obj2 = gameObjects.at(j);
            if (obj->getPosX() == obj2->getPosX() && obj->getPosY() == obj2->getPosY()) {
                obj->detectCollision(*obj2);
            }
        }

        // Delete object if needed
        if (obj->isDestroyed() || obj->getPosX() > _width || obj->getPosY() > _height || obj->getPosY() < 0 || obj->getPosX() < 0) {
            gameObjects.erase(gameObjects.begin() + i);
            break;
        }

        // Print game object with color
        wattron(window, COLOR_PAIR(obj->getColor()));
        mvwaddch(window, obj->getPosY(), obj->getPosX(), obj->getRepresentation());
        wattroff(window, COLOR_PAIR(1));
        // Call game objects update function
        obj->update();

        // Write the game message if any
        if (strlen(_message) > 0) {
            int offset = floor(strlen(_message) / 2);
            mvwprintw(window, floor(_height / 2), floor(_width / 2) - offset, _message);
        }
    }
    // Refresh the terminal
    wrefresh(window);
}

void Board::writeMessage(const char* message) {
    _message = message;
}

std::vector<Entity*> Board::getObjects(char representation) {
    std::vector<Entity*> filtered = std::vector<Entity*>();
    for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects.at(i)->getRepresentation() == representation) 
            filtered.push_back(gameObjects.at(i));
    }
    return filtered;
}

int Board::getInput() {
    // Timeout prevents the wgetchar() from blocking
    wtimeout(window, TIMEOUT);
    return wgetch(window);
}

void Board::addObject(Entity* object) {
    gameObjects.push_back(object);
}
