#ifndef player_hpp
#define player_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <bullet.hpp>
#include <vector>

class Player : public sf::Sprite {
public:
    double getSpeed();
    double getAngle();

    Player(sf::Texture &texture_guy);

    void shooting(sf::Time elapsed, std::vector<Bullet> &bullets);

    void moveing(sf::Vector2i mousePosition);

protected:
    int playerRadius = 13;
    double angle = 0;
    double speed = 5;
    double gunSpeed = 0.7;
};
#endif
