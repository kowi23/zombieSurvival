#include "player.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const float pi = M_PI;
const int windowHight = 900;
const int windowWidth = 1400;

std::string Player::name() { return name_; }
double Player::getSpeed(){return speed;};
double Player::max_speed() { return max_speed_; }

Player::Player(sf::Texture &texture_guy){
    this->setTexture(texture_guy);
    this->setOrigin(13,21);
    this->setPosition(400,300);
}

void Player::shooting(sf::Time elapsed){
static double reload = 0;

if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && reload == 0){
        //bullets.emplace_back(CustomRectangleShape(angle, this->getPosition()));
        std::cout<<"shoot"<<std::endl;
        reload += elapsed.asSeconds();
 }
if(reload != 0){
     reload += elapsed.asSeconds();
     if(reload>gunSpeed){
         reload=0;
     }
}
}

void Player::moveing(sf::Vector2i mousePosition){
//player angle
sf::Vector2f playerPosition = this->getPosition();
double angle = atan((mousePosition.x-playerPosition.x)/(playerPosition.y-mousePosition.y))*180/pi;

if(mousePosition.y>playerPosition.y){
    if(mousePosition.x>playerPosition.x){
        angle+=180;
    }else{
        angle-=180;
    }
}
//rotation
this->setRotation(angle);

//move
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    this->move(std::cos((angle+90)*pi/180)*speed, std::sin((angle+90)*pi/180)*speed);
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    this->move(std::cos(angle*pi/180)*speed, std::sin(angle*pi/180)*speed);
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    this->move(std::cos((angle-180)*pi/180)*speed, std::sin((angle-180)*pi/180)*speed);
}
//walls
if(playerPosition.x<playerRadius){
    this->setPosition(playerRadius,playerPosition.y);
}
if(playerPosition.y<playerRadius){
    this->setPosition(playerPosition.x,playerRadius);
}
if(playerPosition.y>windowHight-playerRadius){
    this->setPosition(playerPosition.x,windowHight-playerRadius);
}
if(playerPosition.x>windowWidth-playerRadius){
    this->setPosition(windowWidth-playerRadius,playerPosition.y);
}

}
