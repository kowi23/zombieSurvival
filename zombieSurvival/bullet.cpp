#include "bullet.hpp"



Bullet::Bullet(double angle, sf::Vector2f startPosition, clock_t time, int damage, int life){
   this->setRadius(bulletRadius);
   this->setPosition(startPosition);
   this->setFillColor(sf::Color(100, 250, 50));
   this->setOrigin(bulletRadius/2,bulletRadius/2);
   angle_ = angle;
   startTime_ = time;
   damage_ = damage;
   life_ = life;
}


void Bullet::moveing(clock_t time, std::vector<Bullet> &bullets, int index){

    ///move
    this->move(std::cos((angle_-90)*pi/180)*speed, std::sin((angle_-90)*pi/180)*speed);
    ///walls
    sf::Vector2f bulletPosition = this->getPosition();
    if(bulletPosition.x<bulletRadius){
        angle_ = fabs(angle_);
    }
    if(bulletPosition.y<bulletRadius || bulletPosition.y>windowHight-75-bulletRadius){
        if(angle_ > 0){
            angle_ = 180 - angle_;
        }else{
            angle_ = -180-angle_;
        }
    }
    if(bulletPosition.x>windowWidth-bulletRadius){
       angle_ = -fabs(angle_);
    }
    ///bullet life
    if(time-startTime_>life_){

            bullets.erase(bullets.begin()+index);
    }

}
void Bullet::hit(std::vector<Monster> &monsters, std::vector<Bullet> &bullets, int index){

    sf::Vector2f bulletPosition = this->getPosition();

    for (int i = 0; i < monsters.size(); i++){
        if(cordsDistance(bulletPosition,monsters[i].getPosition())<=monsters[i].getStrength()+bulletRadius){
            monsters[i].subtractHealth(damage_, monsters, i);
            bullets.erase(bullets.begin()+index);
            break;
        }
    }
}
