#include "player.hpp"

class Bullet;

///////GETTERS

float Player::getSpeed(){return speed;};
float Player::getAngle(){return angle;};
int Player::getRadius(){return playerRadius;};
void Player::subtractHealth(int n){health_ -= n; std::cout<<health_<<std::endl;}

/////////CONSTRUCTOR
Player::Player(sf::Texture &texture){
    this->setTexture(texture);
    this->setOrigin(13,21);
    this->setPosition(400,300);
}
////////SHOOTING
void Player::shooting(clock_t time, std::vector<Bullet> &bullets){
static double reload = 0;

if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && reload == 0){

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
void Player::moveing(sf::Vector2f mousePosition){
//player angle
sf::Vector2f playerPosition = this->getPosition();
angle = calculateAngle(playerPosition,mousePosition);


//rotation
this->setRotation(angle);

//move

if(fabs(mousePosition.x-playerPosition.x)>playerRadius || fabs(mousePosition.y-playerPosition.y)>playerRadius){

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
