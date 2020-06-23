#include "bullet.hpp"


bool Bullet::isGranade(){return isGranade_;}

Bullet::Bullet(double angle, sf::Vector2f startPosition, clock_t time, int damage, int life){
   this->setRadius(bulletRadius_);
   this->setPosition(startPosition);
   this->setFillColor(sf::Color(100, 250, 50));
   this->setOrigin(bulletRadius_,bulletRadius_);
   angle_ = angle;
   startTime_ = time;
   damage_ = damage;
   life_ = life;
}
Bullet::Bullet(double angle, sf::Vector2f startPosition, clock_t time){
    bulletRadius_ = 8;
    this->setRadius(bulletRadius_);
    this->setPosition(startPosition);
    this->setFillColor(sf::Color(100, 250, 50));
    this->setOrigin(bulletRadius_,bulletRadius_);
    angle_ = angle;
    startTime_ = time;
    isGranade_ = true;
    damage_ = 150;
    life_ = 2000;
    speed_ = 15;
}

void Bullet::moveing(clock_t time, std::vector<Bullet> &bullets, int index, std::vector<Monster> &monsters){

///move
    this->move(std::cos((angle_-90)*pi/180)*speed_, std::sin((angle_-90)*pi/180)*speed_);
///isGranade? if not-> hit()
    if(isGranade_){
        speed_ *= 0.95;
        if(speed_ < 0.5){
            speed_ = 0;
        }
    }else{
        this->hit(monsters, bullets, index);
    }
///walls
    sf::Vector2f bulletPosition = this->getPosition();
    if(bulletPosition.x<bulletRadius_){
        angle_ = fabs(angle_);
    }
    if(bulletPosition.y<bulletRadius_ || bulletPosition.y>windowHight-75-bulletRadius_){
        if(angle_ > 0){
            angle_ = 180 - angle_;
        }else{
            angle_ = -180-angle_;
        }
    }
    if(bulletPosition.x>windowWidth-bulletRadius_){
       angle_ = -fabs(angle_);
    }
///bullet life
    if(time-startTime_>life_){
            if(isGranade_){
             this->granadeBoom(monsters);
            }
            bullets.erase(bullets.begin()+index);
    }

}

void Bullet::granadeBoom(std::vector<Monster> &monsters){
    sf::Vector2f bulletPosition = this->getPosition();

    for (int i = 0; i < monsters.size(); i++){
        if(cordsDistance(bulletPosition,monsters[i].getPosition())<=75){
            monsters[i].subtractHealth(damage_*2, monsters, i);
        }else if(cordsDistance(bulletPosition,monsters[i].getPosition())<=150){
            monsters[i].subtractHealth(damage_, monsters, i);
        }
    }
}
void Bullet::hit(std::vector<Monster> &monsters, std::vector<Bullet> &bullets, int index){

    sf::Vector2f bulletPosition = this->getPosition();

    for (int i = 0; i < monsters.size(); i++){
        if(cordsDistance(bulletPosition,monsters[i].getPosition())<=monsters[i].getStrength()+bulletRadius_){
            monsters[i].subtractHealth(damage_, monsters, i);
            bullets.erase(bullets.begin()+index);
            break;
        }
    }
}
