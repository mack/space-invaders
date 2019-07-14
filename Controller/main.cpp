
//
//  main.cpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#include <iostream>
#include <curses.h>
#include <math.h>

#include "Board.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "Alien.hpp"
#include "Constants.hpp"

int main() {
    Board* board = new Board(50, 40);
    int round = 0;

    // Create a player and add it to the board
    Player* player = new Player(floor(board->getWidth() / 2), board->getHeight() - 1);
    board->addObject(player);

    // Create aliens and add to board
    int midSpace = floor(board->getWidth() / 2);
    int numRows = 2;
    int numCols = 4;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        //don't know why we have to add this pointer to generate correct # of aliens but it breaks otherwise
        Alien* alien = new Alien(midSpace - (numCols/2) + j, i+1);
       // board->addObject(alien);
        board->addObject(new Alien(midSpace - (numCols/2) + j, i+1));
      }
    }

    while (true) {
      // Check if game is over
      if (player->getLives() <= 0) {
        board->writeMessage("Game Over.");
      } else if (board->getObjects(ALIEN_REP).size() == 0) {
        //board->writeMessage("You win!!");
        round++;
        for (int i = 0; i < numRows; i++) {
          for (int j = 0; j < numCols; j++) {
            Alien* alien = new Alien(midSpace - (numCols/2) + j, i+1, round);
       // board->addObject(alien);
            board->addObject(new Alien(midSpace - (numCols/2) + j, i+1, round));
      }
    }
      } else {
          auto aliens = board->getObjects(ALIEN_REP);
          for (auto& alien : aliens) {
              if (alien->getPosY() > player->getPosY()) {
                  player->loseLife();
              }
          }
      }

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
                board->addObject(new Projectile(true, player->getPosX(), player->getPosY() - 1));
                //board->addObject(p);
                break;
            default:
        }
    }
}

