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

void Player::moveRight()
{
  setPos(_position[0] + 1, _position[1]);
}

void Player::moveLeft()
{
  setPos(_position[0] - 1, _position[1]);
}

Projectile Player::shoot()
{
  return Projectile(true, getPosX(), getPosY() + 1);
}

int Player::getLives(){
  return _lives;
}

void Player::update(){

}

void Player::loseLife(){
  _lives = _lives - 1;
}

void Player::resetLives(){
  _lives = DEF_LIVES;
}
