#include "monster.hpp"


Monster::Monster(sf::Texture &texture){
    this->setTexture(texture);///orginalnie 30x30
    this->setScale(1/(15.f/strength),1/(15.f/strength));
    this->setPosition(700,-10);

}

void Monster::moveing(sf::Vector2f playerPosition){
    ////angle
    sf::Vector2f monsterPosition = this->getPosition();
    angle = calculateAngle(monsterPosition,playerPosition);
    this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);
    ////obrot
    this->setRotation(angle);
}
