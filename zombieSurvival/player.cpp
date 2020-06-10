#include "player.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <bullet.hpp>
#include <vector>
#include <constants.hpp>


///////GETTERS

double Player::getSpeed(){return speed;};
double Player::getAngle(){return angle;};

/////////CONSTRUCTOR
Player::Player(sf::Texture &texture_guy){
    this->setTexture(texture_guy);
    this->setOrigin(13,21);
    this->setPosition(400,300);
}
////////SHOOTING
void Player::shooting(clock_t time, std::vector<Bullet> &bullets){
static double reload = 0;

if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && reload == 0){
        std::cout<<"shoot"<<angle<<std::endl;
        bullets.emplace_back(Bullet(angle,this->getPosition(),time));
        reload = time;
 }
if(reload != 0){
     if(time-reload>gunSpeed){
         reload=0;
     }
}
}
/////////////MOVEING
void Player::moveing(sf::Vector2i mousePosition){
//player angle
sf::Vector2f playerPosition = this->getPosition();
angle = atan((mousePosition.x-playerPosition.x)/(playerPosition.y-mousePosition.y))*180/pi;

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
