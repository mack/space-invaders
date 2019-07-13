//
//  Entity.hpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <curses.h>

class Entity {
protected:
  float* _position;
  int _color = COLOR_WHITE;
  int _velocity;
  char _representation;
  bool _destroyed;

public:
  Entity();
  Entity(float x, float y);
  virtual ~Entity();
  float* getPos();
  int getColor();
  int getVel();
  void setPos(float x, float y);
  int getPosX();
  int getPosY();
  void destroy();
  bool isDestroyed();
  char getRepresentation();
  virtual void update() = 0;
  virtual void detectCollision(Entity& object);
};
#endif
