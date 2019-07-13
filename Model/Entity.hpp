//
//  Entity.hpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
class Entity {
protected:
protected:
  static int nextID;
  int* _position;
  int _id;
  int _color;
  int _velocity;
  char _representation;
public:
  Entity();
  Entity(int x, int y);
  virtual ~Entity();
  int* getPos();
  int getID();
  int getColor();
  int getVel();
  void setPos(int x, int y);
  int getPosX();
  int getPosY();
  char getRepresentation();
  virtual void update();
};
#endif /* Entity_hpp */
