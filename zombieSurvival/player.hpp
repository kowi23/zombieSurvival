#ifndef player_hpp
#define player_hpp

#include <myFunctions.hpp>
#include "bullet.hpp"



class Player : public sf::Sprite {
public:
    void subtractHealth(int n);
    void changedWeapond(weapond weapond);
    void changingWeapond(sf::Event event, sf::RectangleShape &weapondBackground);
    //getters
    float getSpeed();
    int getGranadeNum();
    int getHealth();
    float getAngle();
    int getRadius();

    Player();
    bool itemContact(sf::FloatRect itemBounds, itemType itemType);

    void shooting(clock_t time, std::vector<Bullet> &bullets, sf::RectangleShape &weapondBackground);

    void moveing(sf::Vector2f mousePosition);

protected:
    int playerRadius_ = constPlayerRadius;
    float angle_;
    float speed_ = 2.5;
    int gunSpeed_ = 700;//czas strzalu w ms
    int health_ = 1000;
    weapond changedWeapond_ = weapond::Handgun;
    int granadeNum_ = 5;
};
#endif
