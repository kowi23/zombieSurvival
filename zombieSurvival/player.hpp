#ifndef player_hpp
#define player_hpp

#include <myFunctions.hpp>
#include "bullet.hpp"

enum class weapond {
    Handgun,
    Rifle,
    Shotgun,
    SniperRifle,
};

class Player : public sf::Sprite {
public:
    void subtractHealth(int n);
    void changedWeapond(weapond weapond);
    void changingWeapond(sf::Event event, sf::RectangleShape &weapondBackground);
    //getters
    float getSpeed();
    float getAngle();
    int getRadius();

    Player(sf::Texture &texture_guy);

    void shooting(clock_t time, std::vector<Bullet> &bullets);

    void moveing(sf::Vector2f mousePosition);

protected:
    int playerRadius = constPlayerRadius;
    float angle_;
    float speed = 5;
    int gunSpeed_ = 700;//czas strzalu w ms
    int health_ = 1000;
    weapond changedWeapond_ = weapond::Handgun;
};
#endif
