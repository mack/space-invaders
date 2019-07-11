//
//  Alien.hpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#ifndef alien_hpp
#define alien_hpp

#include <stdio.h>
#include "entity.hpp"

class alien : public entity{
private:
  int _value;
  int _health;
public:
  alien();
  ~alien();
  int getValue();
  int getHealth();
  void takeDamage(int damage);
};
#endif /* Alien_hpp */
