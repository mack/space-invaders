//
//  Player.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "player.hpp"
#define DEF_LIVES 3

Player::Player(){
  _lives = DEF_LIVES;
}

Player::~Player(){

}

int Player::getLives(){
  return _lives;
}


void Player::loseLife(){
  _lives = _lives - 1;
}

void Player::resetLives(){
  _lives = DEF_LIVES;
}
