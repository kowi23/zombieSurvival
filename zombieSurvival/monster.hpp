#ifndef monster_hpp
#define monster_hpp
#include <myFunctions.hpp>

class Monster : public sf::Sprite {
public:

    Monster(sf::Texture &texture, float speed, int strength, int health, float difficultLevel);

    //getters
    float getSpeed();
    float getAngle();
    int getStrength();
    bool isBiting();//zwraca czy potwor gryzie gracza

    void subtractHealth(int n,std::vector<Monster> &monsters, int index); //odejmuje zdrowie potworowi, gdy zdejdzie do 0 niszczy potwora

    void moveing(sf::Vector2f playerPosition, std::vector<Monster> &monsters, int index);//ruch potwora, wykrywa kontakt z graczem  innymi potworami

protected:
    int strength_ = 13;//jednoczesnie promien zombie
    float angle_ = 0;
    float speed_ = 3;
    int health_ = 100;
    bool biting_ = false;
};



#endif
