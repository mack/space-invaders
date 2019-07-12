//
//  Entity.hpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#ifndef entity_hpp
#define entity_hpp

#include <stdio.h>
class Entity {
protected:
  int* _position;
  int _color;
  int _velocity;
public:
  Entity();
  Entity(int x, int y);
  virtual ~Entity();
  int* getPos();
  int getColor();
  int getVel();
  void setPos(int x, int y);
  int getPosX();
  int getPosY();
  virtual void update();
};
#endif /* Entity_hpp */
