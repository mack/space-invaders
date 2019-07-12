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
#include "Projectile.hpp"
#include "Alien.hpp"
#include <curses.h>
#include <math.h>

// This will become the "Game Engine" file...

#define RIGHT_KEY 'C'
#define LEFT_KEY 'D'
#define UP_KEY 'A'

int main() {
    Board* board = new Board(100, 40);
    // Create a player and add it to the board
    Player* player = new Player(floor(board->getWidth() / 2), board->getHeight() - 1);
    board->addObject(player);

    // Create aliens and add to board
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 50; j++) {
        Alien* alien = new Alien(j+21, i+1);
        board->addObject(alien);
      }
    }

    while (true) {
      board->update();      
      // Check for user input
      int c = board->getInput();
      switch(c) {
            case RIGHT_KEY:
                player->moveRight();
                break;
            case LEFT_KEY:
                player->moveLeft();
                break;
            case UP_KEY:
                Projectile* p = new Projectile(true, player->getPosX(), player->getPosY() - 1);
                board->addObject(p);
                break;
        }
    }
}
