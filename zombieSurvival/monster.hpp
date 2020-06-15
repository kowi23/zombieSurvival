#ifndef monster_hpp
#define monster_hpp
#include <myFunctions.hpp>

class Monster : public sf::Sprite {
public:
    double getSpeed();
    double getAngle();
    double getStrength();
    bool isBiting();
    void subtractHealth(int n);
    Monster(sf::Texture &texture);

    void moveing(sf::Vector2f playerPosition, std::vector<Monster> &monsters, int index);

protected:
    int strength = 13;//jednoczesnie promien zombie
    double angle = 0;
    double speed = 2;
    int health_ = 100;
    bool biting_ = false;
};



#endif
