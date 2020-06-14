#ifndef monster_hpp
#define monster_hpp
#include "myFunctions.hpp"

class Monster : public sf::Sprite {
public:
    double getSpeed();
    double getAngle();

    Monster(sf::Texture &texture);

    void moveing(sf::Vector2f playerPosition);

protected:
    int strength = 5;
    double angle = 0;
    double speed = 1;
    double gunSpeed = 150;//czas strzalu w ms
};



#endif