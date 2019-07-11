//
//  Player.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "player.hpp"
#define DEF_LIVES 3

player::player(){
  _lives = DEF_LIVES;
}

player::~player(){

}

int player::getLives(){
  return _lives;
}


void player::loseLife(){
  _lives = _lives - 1;
}

void player::resetLives(){
  _lives = DEF_LIVES;
}
