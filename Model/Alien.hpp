
//  Alien.hpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#ifndef Alien_hpp
#define Alien_hpp

#include <stdio.h>

#include "Entity.hpp"

class Alien : public Entity {
private:
  int _value;
  int _health;
  int _moveState;
  int _moveStateDownToggle;

public:
  Alien();
  Alien(int x, int y);
  Alien(int x, int y, int v);
  ~Alien();
  int getValue();
  int getHealth();
  int takeDamage(int damage);
  void update() override;
  void detectCollision(Entity& object) override;
};
#endif

