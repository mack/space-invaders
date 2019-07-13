//
//  Projectile.cpp
//  Space Invaders
//
//  Created by Mackenzie Boudreau, Ian Page, Carter McCullum, Branden Rice on 2019-07-10.
//  Copyright © 2019 Group 9. All rights reserved.
//

#include "Projectile.hpp"
#include "Constants.hpp"

Projectile::Projectile(bool alignment)
: _power(1), _friendly(alignment) {
 _representation = PROJECTILE_REP;
}

Projectile::Projectile(bool alignment, int xPosition, int yPosition)
: Entity(xPosition, yPosition), _power(1), _friendly(alignment) {
    _representation = PROJECTILE_REP;
}

Projectile::~Projectile() {}

int Projectile::getPower(){
    return _power;
}

bool Projectile::getFriendly(){
    return _friendly;
}

void Projectile::update() {
    setPos(getPosX(), getPosY() - 1);
}
