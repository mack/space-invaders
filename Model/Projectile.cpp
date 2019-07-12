#include "projectile.hpp"

Projectile::Projectile(bool alignment)
{
    _power = 1;
    _friendly = alignment;
} 

Projectile::~Projectile(){

}

int Projectile::getPower(){
    return _power;
}

bool Projectile::getFriendly(){
    return _friendly;
}

void Projectile::update() {
    setPos(_position[0], _position[1] + 1);
}


