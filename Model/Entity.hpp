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
class entity {
private:
  int* _position;
  int _color;
  int _velocity;
public:
  entity();
  virtual ~entity();
  int* getPos();
  int getColor();
  int getVel();
  void setPos(int x, int y);
};
#endif /* Entity_hpp */
