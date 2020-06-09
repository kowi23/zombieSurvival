#ifndef player_hpp
#define player_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Bullet : public sf::CircleShape {
public:
Bullet(double angle_, sf::Vector2f startPosition);
void moveing();
protected:
double life;//bedzie zalezne od damage
double speed;
double angle;
int damage = 4;
};
#endif
