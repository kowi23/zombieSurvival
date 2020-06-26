#include "player.hpp"

float Player::getSpeed(){return speed_;}

int Player::getHealth(){return health_;}

float Player::getAngle(){return angle_;}

int Player::getRadius(){return playerRadius_;}

int Player::getGranadeNum(){return granadeNum_;}

void Player::setSpeed(float speed){speed_ = speed;}

void Player::subtractHealth(int n){health_ -= n;}

void Player::changedWeapond(weapond weapond){changedWeapond_ = weapond;}
std::set<itemType> Player::availableWeaponds(){return availableWeaponds_;}
/////////CONSTRUCTOR
Player::Player(){
    this->setOrigin(13,21);
    this->setPosition(400,300);
}
bool Player::itemContact(sf::FloatRect itemBounds, itemType itemType){
    if(this->getGlobalBounds().intersects(itemBounds)){
        switch ( itemType )
          {
             case itemType::Health:
                health_ +=200;
                if(health_>1000){
                    health_ = 1000;
                }
                break;
             case itemType::Granade:
                granadeNum_++;
                break;
             case itemType::Rifle:
                availableWeaponds_.emplace(itemType::Rifle);
                break;
             case itemType::Shotgun:
                availableWeaponds_.emplace(itemType::Shotgun);
                break;
             case itemType::SniperRifle:
                availableWeaponds_.emplace(itemType::SniperRifle);
                break;
             default:
                break;
          }
        return true;
    }else{
        return false;
    }
}
////////CHANGING WEAPOND
void Player::changingWeapond(sf::Event event, sf::RectangleShape &weapondBackground){
    switch ( event.key.code )
      {
         case sf::Keyboard::Num1:
            changedWeapond_ = weapond::Handgun;
            gunSpeed_ = 700;
            weapondBackground.setPosition(0,windowHight-75);
            break;
         case sf::Keyboard::Num2:
            if(availableWeaponds_.find(itemType::Rifle)!=availableWeaponds_.end()){
                changedWeapond_ = weapond::Rifle;
                gunSpeed_ = 150;
                weapondBackground.setPosition(150,windowHight-75);
            }
            break;
         case sf::Keyboard::Num3:
            if(availableWeaponds_.find(itemType::Shotgun)!=availableWeaponds_.end()){
                changedWeapond_ = weapond::Shotgun;
                gunSpeed_ = 700;
                weapondBackground.setPosition(300,windowHight-75);
             }
            break;
         case sf::Keyboard::Num4:
            if(availableWeaponds_.find(itemType::SniperRifle)!=availableWeaponds_.end()){
                changedWeapond_ = weapond::SniperRifle;
                gunSpeed_ = 900;
                weapondBackground.setPosition(450,windowHight-75);
             }
            break;
         case sf::Keyboard::Num5:
            if(granadeNum_>0){
                changedWeapond_ = weapond::Granade;
                gunSpeed_ = 1000;
                weapondBackground.setPosition(600,windowHight-75);
            }
            break;
         default:
            break;
      }

}
////////SHOOTING
void Player::shooting(clock_t time, std::vector<Bullet> &bullets,  sf::RectangleShape &weapondBackground){
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
        if(changedWeapond_ == weapond::Granade){
            bullets.emplace_back(Bullet(bulletAngle,this->getPosition(),time));
            granadeNum_--;
            if(granadeNum_<=0){
                changedWeapond_ = weapond::Handgun;
                gunSpeed_ = 700;
                weapondBackground.setPosition(0,windowHight-75);
            }
        }else{
            bullets.emplace_back(Bullet(bulletAngle,this->getPosition(),time, damage, bulletLife));
            if(changedWeapond_ == weapond::Shotgun){
                for (int i = 0; i < 5; i++){
                    bullets.emplace_back(Bullet(bulletAngle+(std::rand() % 61)-30,this->getPosition(),time, damage, bulletLife));
                }
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
    float moveX = 0;
    float moveY = 0;
    if(fabs(mousePosition.x-playerPosition.x)>playerRadius_ || fabs(mousePosition.y-playerPosition.y)>playerRadius_){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                moveX = std::cos((angle_-90)*pi/180)*speed_;
                moveY = std::sin((angle_-90)*pi/180)*speed_;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                moveX = std::cos((angle_+90)*pi/180)*speed_;
                moveY = std::sin((angle_+90)*pi/180)*speed_;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                moveX = std::cos((angle_)*pi/180)*speed_;
                moveY = std::sin((angle_)*pi/180)*speed_;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                moveX = std::cos((angle_-180)*pi/180)*speed_;
                moveY = std::sin((angle_-180)*pi/180)*speed_;
            }

    }
    //walls
    if(playerPosition.x<playerRadius_ && moveX<0){
        moveX = 0;
    }
    if(playerPosition.y<playerRadius_ && moveY<0){
        moveY = 0;
    }
    if(playerPosition.y>windowHight-75-playerRadius_ && moveY>0){
        moveY = 0;
    }
    if(playerPosition.x>windowWidth-playerRadius_ && moveX>0){
        moveX = 0;
    }
    this->move(moveX,moveY);

}
