//
//  board.hpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <iostream>
#include <curses.h>
#include <vector>
#include <Entity.hpp>

class Board {
private:
    int _width;
    int _height;
    WINDOW *window;
    std::vector<Entity*> gameObjects;

public:
    Board();
    Board(int width, int height);
    ~Board();
    int getHeight();
    int getWidth();
    void update();
    void addObject(Entity* object);
    int getInput();
    void checkCollision();
};

#endif /* board_hpp */
