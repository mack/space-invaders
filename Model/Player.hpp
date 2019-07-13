//
//  Player.hpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "Projectile.hpp"

class Player : public Entity{
private:
  int _lives;
public:
  Player();
  Player(int x, int y);
  ~Player();
  int getLives();
  void loseLife();
  void resetLives();
  void update() override;
  void moveLeft();
  void moveRight();
  Projectile shoot();
};
#endif /* Player_hpp */
