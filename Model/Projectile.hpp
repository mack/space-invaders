 
#ifndef projectile_hpp
#define projectile_hpp

#include <stdio.h>
#include "entity.hpp"

class Projectile : public Entity{
private:
    int _power;
    bool _friendly;
public:
    Projectile(bool alignment);
    ~Projectile();
    int getPower();
    bool getFriendly();
    void update() override;
};

#endif