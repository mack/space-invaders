#include "projectile.hpp"

Projectile::Projectile(bool alignment)
: _power(1), _friendly(alignment)
{
 
} 

Projectile::Projectile(bool alignment, int xPosition, int yPosition)
: Entity(xPosition, yPosition), _power(1), _friendly(alignment)
{

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
    setPos(getPosX(), getPosY() + 1);
}


