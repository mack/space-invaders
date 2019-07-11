//
//  Entity.cpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(){

}

Entity::~Entity(){

}

int* Entity::getPos(){ return _position; }
int Entity::getColor(){ return _color; }
int Entity::getVel(){ return _velocity; }

void Entity::setPos(int x, int y){
  _position[0] = x;
  _position[1] = y;
}
