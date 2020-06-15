#ifndef monster_hpp
#define monster_hpp
#include "myFunctions.hpp"
#include "player.hpp"

class Monster : public sf::Sprite {
public:
    double getSpeed();
    double getAngle();
    double getStrength();
    Monster(sf::Texture &texture);

    void moveing(Player &player, std::vector<Monster> monsters, int index);

protected:
    int strength = 13;//jednoczesnie promien zombie
    double angle = 0;
    double speed = 2;
    bool biting_ = false;
};



#endif
