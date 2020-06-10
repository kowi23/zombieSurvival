#ifndef bullet_hpp
#define bullet_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Bullet : public sf::CircleShape {
public:
Bullet(double angle_, sf::Vector2f startPosition);
void moveing();
protected:
double life;//bedzie zalezne od damage
double speed = 50;
double angle;
double damage = 4;
double bulletRadius = 4;
};
#endif
