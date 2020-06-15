#ifndef bullet_hpp
#define bullet_hpp
#include <myFunctions.hpp>
#include "monster.hpp"



class Bullet : public sf::CircleShape {
public:
    Bullet(double angle_, sf::Vector2f startPosition, clock_t time);
    void hit(std::vector<Monster> &monsters, std::vector<Bullet> &bullets, int index);
    void moveing(clock_t time, std::vector<Bullet> &bullets, int index);
protected:
    int life = 1000;//bedzie zalezne od damage, w ms
    int speed = 50;
    float angle;
    int damage_ = 40;
    int bulletRadius = 4;
    clock_t startTime;

};

#endif
