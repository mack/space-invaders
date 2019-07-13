//
//  Alien.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "Alien.hpp"
#define DEF_VALUE 100
#define DEF_HEALTH 100
#define CHAR_REP 'A'

Alien::Alien(){
  _value = DEF_VALUE;
  _health = DEF_HEALTH;
  _representation = CHAR_REP;
}

Alien::Alien(int xPosition, int yPosition)
: Entity(xPosition, yPosition)
{
  _value = DEF_VALUE;
  _health = DEF_HEALTH;
  _representation = CHAR_REP;
}

Alien::~Alien(){

}

int Alien::getValue(){
  return _value;
}

int Alien::getHealth(){
  return _health;
}

void Alien::takeDamage(int damage){
  _health = _health - damage;
}

void Alien::update(){

}
