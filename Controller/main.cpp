//
//  main.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include <iostream>
#include "board.hpp"

// This will become the "Game Engine" file...
#define WIDTH 30
#define HEIGHT 10

int main() {
    // TODO: This stuff should probably be in the board files.
    Board* b = new Board(10, 20);
    b->setup();
    return 0;
}
