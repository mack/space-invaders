
//
//  Alien.cpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#include<algorithm>
#include <curses.h>

#include "Board.hpp"
#include "Alien.hpp"
#include <Constants.hpp>

#define DEF_VALUE 100
#define DEF_HEALTH 100

Alien::Alien() {
  _value = DEF_VALUE;
  _health = DEF_HEALTH;
  _representation = ALIEN_REP;
  _color = COLOR_GREEN;
}

Alien::Alien(int xPosition, int yPosition)
: Entity(xPosition, yPosition) {
  _value = DEF_VALUE;
  _health = DEF_HEALTH;
  _representation = ALIEN_REP;
  _color = COLOR_GREEN;
  _velocity = 1;
}

Alien::Alien(int xPosition, int yPosition, int velocity)
: Entity(xPosition, yPosition){
  _value = DEF_VALUE;
  _health = DEF_HEALTH;
  _representation = ALIEN_REP;
  _color = COLOR_GREEN;
  _velocity = velocity;
}

Alien::~Alien() {}

int Alien::getValue() {
  return _value;
}

int Alien::getHealth() {
  return _health;
}

int Alien::takeDamage(int damage) {
  _health = std::max(_health - damage, 0);
  return _health;
}

void Alien::update() {
  if (_health <= 33) {
    _color = COLOR_RED;
  } else if (_health <= 66) {
    _color = COLOR_MAGENTA;
  }
  setPos(_position[0] - 0.05 - 0.05* _velocity, _position[1] );
}

void Alien::detectCollision(Entity& object) {
  if (object.getRepresentation() == PROJECTILE_REP) {
    if (takeDamage(34) == 0) {
      Board::score++;
      destroy();
    }
    object.destroy();
  }
}



