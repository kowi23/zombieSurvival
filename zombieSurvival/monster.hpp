#ifndef monster_hpp
#define monster_hpp
#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <constants.hpp>

class Monster : public sf::CircleShape {
public:
    double getSpeed();
    double getAngle();

    Monster();

    void moveing(sf::Vector2f playerPosition);

protected:
    int strength = 5;
    double angle = 0;
    double speed = 5;
    double gunSpeed = 150;//czas strzalu w ms
};



#endif
