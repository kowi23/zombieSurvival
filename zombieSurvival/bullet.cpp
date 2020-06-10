#include "bullet.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const float pi = M_PI;
const int windowHight = 900;
const int windowWidth = 1400;

Bullet::Bullet(double angle_, sf::Vector2f startPosition){
   this->setRadius(damage);
   this->setPosition(startPosition);
   this->setFillColor(sf::Color(100, 250, 50));
   this->setOrigin(damage/2,damage/2);
   angle = angle_;
   std::cout<<angle_<<"konstruktor"<<angle<<std::endl;
}
void Bullet::moveing(){
    this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);

};
