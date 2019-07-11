//
//  main.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include <iostream>
#include "board.hpp"
#include <curses.h>

// This will become the "Game Engine" file...
#define WIDTH 30
#define HEIGHT 10

int main() {
    // TODO: This stuff should probably be in the board files.
    Board* b = new Board();
    b->update();
    // while (true) {
    //   b->update();
    //   timeout(-1);
    //   int c = getch();
    //   switch(c) { // the real value
    //         case KEY_RIGHT:
    //             b->movePlayer(1);
    //             break;
    //         case KEY_LEFT:
    //             b->movePlayer(-1);
    //             break;
    //     }
    // }
    return 0;

}
