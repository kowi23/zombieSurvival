#include "player.hpp"

class Bullet;

///////GETTERS

float Player::getSpeed(){return speed;};
float Player::getAngle(){return angle_;};
int Player::getRadius(){return playerRadius;};
void Player::subtractHealth(int n){health_ -= n;}
void Player::changedWeapond(weapond weapond){changedWeapond_ = weapond;}

/////////CONSTRUCTOR
Player::Player(sf::Texture &texture){
    this->setTexture(texture);
    this->setOrigin(13,21);
    this->setPosition(400,300);
}
////////CHANGING WEAPOND
void Player::changingWeapond(sf::Event event){
    if (event.key.code == sf::Keyboard::Num1){
        changedWeapond_ = weapond::Handgun;
        gunSpeed_ = 850;
    }else if (event.key.code == sf::Keyboard::Num2){
        changedWeapond_ = weapond::Rifle;
        gunSpeed_ = 150;
    }else if (event.key.code == sf::Keyboard::Num3){
        changedWeapond_ = weapond::Shotgun;
        gunSpeed_ = 700;
    }else if (event.key.code == sf::Keyboard::Num4){
        changedWeapond_ = weapond::SniperRifle;
        gunSpeed_ = 900;
    }

}
////////SHOOTING
void Player::shooting(clock_t time, std::vector<Bullet> &bullets){
static double reload = 0;

if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && reload == 0){
        int damage;
        int bulletLife;
        float bulletAngle = angle_;
        switch ( changedWeapond_ )
          {
             case weapond::Handgun:
                damage = 30;
                bulletLife = 1000;
                break;
             case weapond::Rifle:
                damage = 30;
                bulletLife = 1000;
                bulletAngle += (std::rand() % 21)-10;
                break;
             case weapond::Shotgun:
                damage = 20;
                bulletLife = 500;
                break;
             case weapond::SniperRifle:
                damage = 100;
                bulletLife = 2000;
                break;
             default:
                break;
          }
        bullets.emplace_back(Bullet(bulletAngle,this->getPosition(),time, damage, bulletLife));
        if(changedWeapond_ == weapond::Shotgun){
            for (int i = 0; i < 5; i++){
                bullets.emplace_back(Bullet(bulletAngle+(std::rand() % 121)-60,this->getPosition(),time, damage, bulletLife));
            }
        }
        reload = time;
 }
if(reload != 0){
     if(time-reload>gunSpeed_){
         reload=0;
     }
}
}
/////////////MOVEING
void Player::moveing(sf::Vector2f mousePosition){
//player angle
sf::Vector2f playerPosition = this->getPosition();
angle_ = calculateAngle(playerPosition,mousePosition);


//rotation
this->setRotation(angle_);

//move

if(fabs(mousePosition.x-playerPosition.x)>playerRadius || fabs(mousePosition.y-playerPosition.y)>playerRadius){

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            this->move(std::cos((angle_-90)*pi/180)*speed, std::sin((angle_-90)*pi/180)*speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

            this->move(std::cos((angle_+90)*pi/180)*speed, std::sin((angle_+90)*pi/180)*speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            this->move(std::cos(angle_*pi/180)*speed, std::sin(angle_*pi/180)*speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            this->move(std::cos((angle_-180)*pi/180)*speed, std::sin((angle_-180)*pi/180)*speed);
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
