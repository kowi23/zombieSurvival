#ifndef player_hpp
#define player_hpp
#include <bullet.hpp>
#include "myFunctions.hpp"

class Player : public sf::Sprite {
public:
    double getSpeed();
    double getAngle();
    double getRadius();

    Player(sf::Texture &texture_guy);

    void shooting(clock_t time, std::vector<Bullet> &bullets);

    void moveing(sf::Vector2f mousePosition);

protected:
    int playerRadius = 13;
    double angle = 0;
    double speed = 5;
    double gunSpeed = 150;//czas strzalu w ms
};
#endif
