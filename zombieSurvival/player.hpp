#ifndef player_hpp
#define player_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {
public:
    std::string name();
    double getSpeed();
    double max_speed();
    void shooting(sf::Time elapsed);

    Player(sf::Texture &texture_guy);
    void moveing(sf::Vector2i mousePosition);

protected:
    int playerRadius = 13;
    double angle = 0;
    std::string name_;
    double speed = 5;
    double max_speed_;
    double gunSpeed = 0.7;
};
#endif
