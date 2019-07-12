//
//  Entity.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "entity.hpp"
#define DEF_X_POS 1;
#define DEF_Y_POS 1;

Entity::Entity(){
  _position = new int[2];
  _position[0] = DEF_X_POS;
  _position[1] = DEF_Y_POS;
}

Entity::~Entity(){
  delete[] _position;
}

int* Entity::getPos(){
  return _position;
}

int Entity::getColor(){
  return _color;
}

int Entity::getVel(){
  return _velocity;
}

void Entity::setPos(int x, int y){
  _position[0] = x;
  _position[1] = y;
}
