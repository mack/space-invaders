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
class Player : public Entity{
private:
  int _lives;
public:
  Player();
  ~Player();
  int getLives();
  void loseLife();
  void resetLives();
}
#endif /* Player_hpp */
