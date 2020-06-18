#ifndef monster_hpp
#define monster_hpp
#include <myFunctions.hpp>

class Monster : public sf::Sprite {
public:
    float getSpeed();
    float getAngle();
    int getStrength();
    bool isBiting();
    void subtractHealth(int n,std::vector<Monster> &monsters, int index);
    Monster(sf::Texture &texture);

    void moveing(sf::Vector2f playerPosition, std::vector<Monster> &monsters, int index);

protected:
    int strength = 13;//jednoczesnie promien zombie
    float angle = 0;
    float speed = 3;
    int health_ = 100;
    bool biting_ = false;
};



#endif
