//
//  Alien.hpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#ifndef Alien_hpp
#define Alien_hpp

#include <stdio.h>
#include "Entity.hpp"

class Alien : public Entity{
private:
  int _value;
  int _health;
public:
  Alien();
  Alien(int x, int y);
  ~Alien();
  int getValue();
  int getHealth();
  void takeDamage(int damage);
  void update() override;
};
#endif /* Alien_hpp */
