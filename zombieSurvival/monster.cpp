#include "monster.hpp"


Monster::Monster(){
    this->setRadius(10);
    this->setPosition(700,-10);
    this->setFillColor(sf::Color(100, 250, 50));
}

void Monster::moveing(sf::Vector2f playerPosition){
    ////angle
    sf::Vector2f monsterPosition = this->getPosition();
    angle = calculateAngle(monsterPosition,playerPosition);
    this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);
}
