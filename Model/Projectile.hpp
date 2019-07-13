//
//  Projectile.hpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include <stdio.h>

#include "Entity.hpp"

class Projectile : public Entity {
private:
    int _power;
    bool _friendly;

public:
    Projectile(bool alignment);
    Projectile(bool alignment, int x, int y);
    ~Projectile();
    int getPower();
    bool getFriendly();
    void update() override;
};

#endif
