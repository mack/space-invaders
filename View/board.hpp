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

class Board {
private:
    int _width;
    int _height;
    WINDOW *window;
    int pos;

public:
    Board();
    Board(int width, int height);
    ~Board();
    void update();
    void movePlayer(int newX);
};

#endif /* board_hpp */
