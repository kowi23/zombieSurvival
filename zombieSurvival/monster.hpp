#ifndef monster_hpp
#define monster_hpp
#include "myFunctions.hpp"
#include "player.hpp"

class Monster : public sf::Sprite {
public:
    double getSpeed();
    double getAngle();

    Monster(sf::Texture &texture);

    void moveing(Player &player);

protected:
    int strength = 13;//jednoczesnie promien zombie
    double angle = 0;
    double speed = 1;
};



#endif
