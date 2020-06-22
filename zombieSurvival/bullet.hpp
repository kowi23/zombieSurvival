#ifndef bullet_hpp
#define bullet_hpp
#include <myFunctions.hpp>
#include "monster.hpp"



class Bullet : public sf::CircleShape {
public:
    Bullet(double angle, sf::Vector2f startPosition, clock_t time, int damage, int life);
    void hit(std::vector<Monster> &monsters, std::vector<Bullet> &bullets, int index);
    void moveing(clock_t time, std::vector<Bullet> &bullets, int index);
protected:
    int life_ = 1000;//bedzie zalezne od damage, w ms
    int speed = 20;
    float angle_;
    int damage_ = 40;
    int bulletRadius = 4;
    clock_t startTime_;

};

#endif
