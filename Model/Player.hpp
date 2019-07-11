//
//  Player.hpp
//  spaceinvadors
//
//  Created by Mackenzie Boudreau on 2019-07-10.
//  Copyright © 2019 Mackenzie Boudreau. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "entity.hpp"

class player : public entity{
private:
  int _lives;
public:
  player();
  ~player();
  int getLives();
  void loseLife();
  void resetLives();
};
#endif /* Player_hpp */
