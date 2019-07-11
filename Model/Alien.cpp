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

alien::alien(){
  _value = DEF_VALUE;
  _health = DEF_HEALTH;
}

alien::~alien(){

}

int alien::getValue(){
  return _value;
}

int alien::getHealth(){
  return _health;
}

void alien::takeDamage(int damage){
  _health = _health - damage;
}
