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
class Entity{
private:
  int* _position[2];
  int _color;
  int _velocity;
public:
  Entity();
  virtual ~Entity();
  int* getPos();
  int getColor();
  int getVel();
  void setPos(int x, int y);
}
#endif /* Entity_hpp */
