#ifndef bullet_hpp
#define bullet_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>

class Bullet : public sf::CircleShape {
public:
    Bullet(double angle_, sf::Vector2f startPosition, clock_t time);

    void moveing(clock_t time, std::vector<Bullet> &bullets, std::vector<Bullet>::iterator it);
protected:
    double life = 1000;//bedzie zalezne od damage, w ms
    double speed = 50;
    double angle;
    double damage = 4;
    double bulletRadius = 4;
    clock_t startTime;

};
#endif
