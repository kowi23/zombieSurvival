#include "bullet.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <constants.hpp>

Bullet::Bullet(double angle_, sf::Vector2f startPosition){
   this->setRadius(bulletRadius);
   this->setPosition(startPosition);
   this->setFillColor(sf::Color(100, 250, 50));
   this->setOrigin(bulletRadius/2,bulletRadius/2);
   angle = angle_;
}
void Bullet::moveing(){
    ///move
    this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);
    ///walls
    sf::Vector2f bulletPosition = this->getPosition();
    if(bulletPosition.x<bulletRadius){
        angle = fabs(angle);
    }
    if(bulletPosition.y<bulletRadius || bulletPosition.y>windowHight-bulletRadius){
        if(angle > 0){
            angle = 180 - angle;
        }else{
            angle = -180-angle;
        }
    }
    if(bulletPosition.x>windowWidth-bulletRadius){
       angle = -fabs(angle);
    }
};
