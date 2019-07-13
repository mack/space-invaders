//
//  Board.hpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include <curses.h>
#include <vector>
#include <string.h>

#include <Entity.hpp>

class Board {
private:
    int _width;
    int _height;
    const char* _message;
    WINDOW *window;
    std::vector<Entity*> gameObjects;

public:
    Board();
    Board(int width, int height);
    ~Board();
    int getHeight();
    int getWidth();
    void update();
    void writeMessage(const char* message);
    void addObject(Entity* object);
    int getInput();
    std::vector<Entity*> getObjects(char representation);
};

#endif
