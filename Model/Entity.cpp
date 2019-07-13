//
//  Entity.cpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#include "Entity.hpp"
#include <math.h>

#define DEF_X_POS 1.0f;
#define DEF_Y_POS 1.0f;

Entity::Entity() {
  _position = new float[2];
  _position[0] = DEF_X_POS;
  _position[1] = DEF_Y_POS;
}

Entity::Entity(float xPosition, float yPosition) {
  _position = new float[2];
  _position[0] = xPosition;
  _position[1] = yPosition;
}

Entity::~Entity() {
  delete[] _position;
}

float* Entity::getPos() {
  return _position;
}

int Entity::getColor() {
  return _color;
}

int Entity::getVel() {
  return _velocity;
}

void Entity::setPos(float x, float y) {
  _position[0] = x;
  _position[1] = y;
}

int Entity::getPosX() {
  return (int)floor(_position[0]);
}

int Entity::getPosY() {
  return (int)floor(_position[1]);
}

void Entity::destroy() {
  _destroyed = true;
}

bool Entity::isDestroyed() {
  return _destroyed;
}

char Entity::getRepresentation() {
  return _representation;
}

void Entity::update() {}

void Entity::detectCollision(Entity& object) {}