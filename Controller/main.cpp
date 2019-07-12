//
//  main.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include <iostream>
#include "board.hpp"
#include "Player.hpp"
#include <curses.h>
#include <math.h>

// This will become the "Game Engine" file...

#define RIGHT_KEY 'C'
#define LEFT_KEY 'D'
#define UP_KEY 'A'

int main() {
    Board* b = new Board();
    // Create a player and add it to the board
    Player* p = new Player(floor(b->getWidth() / 2), b->getHeight() - 1);
    b->addObject(p);
    
    // Create game objects and add them to the board

    while (true) {
      // Collison detection here ?

      b->update();      
      int c = b->getInput();
      switch(c) { // the real value
            case RIGHT_KEY:
                // p->movePlayer(1);
                break;
            case LEFT_KEY:
                // b->movePlayer(-1);
                break;
            case UP_KEY:
                // Projectile p = new Projectile(p->getXPos ,b->getHeight - 1);
                // b->addObject(p);
                // b->movePlayer(-1);
                break;
        }
    }
}
