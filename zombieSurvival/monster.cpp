#include "monster.hpp"


Monster::Monster(sf::Texture &texture){
    this->setTexture(texture);///orginalnie 30x30
    this->setScale(1/(15.f/strength),1/(15.f/strength));
    this->setOrigin(strength,strength);
    this->setPosition(700,-10);

}

void Monster::moveing(Player &player){
    ////angle
    sf::Vector2f playerPosition = player.getPosition();
    sf::Vector2f monsterPosition = this->getPosition();
    angle = calculateAngle(monsterPosition,playerPosition);
    this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);
    ////obrot
    this->setRotation(angle);
    if(cordsDistance(playerPosition,monsterPosition)<=strength+player.getRadius()){
        std::cout<<cordsDistance(playerPosition,monsterPosition)<<std::endl;
    }
}
