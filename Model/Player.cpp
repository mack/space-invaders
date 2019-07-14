//
//  Player.cpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#include "Player.hpp"
#include <Constants.hpp>

#define DEF_LIVES 2

Player::Player() {
  _lives = DEF_LIVES;
  _representation = PLAYER_REP;
}

Player::Player(int x, int y) {
  _lives = DEF_LIVES;
  _position[0] = x;
  _position[1] = y;
  _representation = PLAYER_REP;
}

Player::~Player() {}

void Player::moveRight() {
  setPos(_position[0] + 1, _position[1]);
}

void Player::moveLeft() {
  setPos(_position[0] - 1, _position[1]);
}

Projectile Player::shoot() {
  return Projectile(true, getPosX(), getPosY() + 1);
}

int Player::getLives() {
  return _lives;
}

void Player::update() {}

void Player::loseLife() {
  _lives = _lives - 1;
}

void Player::resetLives() {
  _lives = DEF_LIVES;
}

void Player::detectCollision(Entity& object) {
  if (object.getRepresentation() == ALIEN_REP) {
    loseLife();
  }
}
