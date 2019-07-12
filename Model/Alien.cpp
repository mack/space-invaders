//
//  Alien.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "alien.hpp"
#define DEF_VALUE 100
#define DEF_HEALTH 100

Alien::Alien(){
  _value = DEF_VALUE;
  _health = DEF_HEALTH;
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
