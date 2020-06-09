#include "bullet.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Bullet::Bullet(double angle_, sf::Vector2f startPosition){
   CircleShape(damage);
   this->setPosition(startPosition);
   this->setFillColor(sf::Color(100, 250, 50));
   angle = angle_;
}
void Bullet::moveing(){

};
