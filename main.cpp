//
//  main.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include <iostream>
#include "board.h"
#include <curses.h>

// This will become the "Game Engine" file...

int main(int argc, const char * argv[]) {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    
    int ch;
    for (;;) {
        if ((ch = getch()) == ERR) {
            
        } else {
            
        }
    }
}
