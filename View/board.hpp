//
//  board.hpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>

class Board {
private:
    int width;
    int height;

public:
    int startx, starty;
    Board();
    Board(int width, int height);
    void setup();
};

#endif /* board_hpp */
