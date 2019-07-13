//
//  Player.hpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

#include "Entity.hpp"
#include "Projectile.hpp"

class Player : public Entity {
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
  void detectCollision(Entity& object) override;
};

#endif
