#ifndef player_hpp
#define player_hpp

#include <myFunctions.hpp>
#include "bullet.hpp"



class Player : public sf::Sprite {
public:

    Player();

    //getters
    std::set<itemType> availableWeaponds();//zwraca odblokowane bronie
    float getSpeed();
    int getGranadeNum();
    int getHealth();
    float getAngle();
    int getRadius();

    void setSpeed(float speed);

    void subtractHealth(int n);//odejmuje zycie gracza

    void changedWeapond(weapond weapond); //zwraca wybrana przez gracza bron

    void changingWeapond(sf::Event event, sf::RectangleShape &weapondBackground); //mechanizm zmiany broni

    bool itemContact(sf::FloatRect itemBounds, itemType itemType);//kontakt i zdobycie przedmiotow, zwraca czy zniszczyc przedmiot

    void shooting(clock_t time, std::vector<Bullet> &bullets, sf::RectangleShape &weapondBackground);//mechanizm strzelania

    void moveing(sf::Vector2f mousePosition);//ruch

protected:
    std::set<itemType> availableWeaponds_;//kolekcja odblokowanych broni
    int playerRadius_ = constPlayerRadius;
    float angle_;
    float speed_ = 2.5;
    int gunSpeed_ = 700;//czas strzalu w ms
    int health_ = 1000;
    weapond changedWeapond_ = weapond::Handgun;
    int granadeNum_ = 1;
};
#endif
