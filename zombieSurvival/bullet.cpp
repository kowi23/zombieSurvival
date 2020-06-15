#include "bullet.hpp"



Bullet::Bullet(double angle_, sf::Vector2f startPosition, clock_t time){
   this->setRadius(bulletRadius);
   this->setPosition(startPosition);
   this->setFillColor(sf::Color(100, 250, 50));
   this->setOrigin(bulletRadius/2,bulletRadius/2);
   angle = angle_;
   startTime = time;
}


void Bullet::moveing(clock_t time, std::vector<Bullet> &bullets, int index){

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
    ///bullet life
    if(time-startTime>life){

            bullets.erase(bullets.begin()+index);
    }

}
void Bullet::hit(std::vector<Monster> &monsters){
    sf::FloatRect bulletBounds = this->getGlobalBounds();

    for (int i = 0; i < monsters.size(); i++){
        if(bulletBounds.intersects(monsters[i].getGlobalBounds())){
            monsters[i].subtractHealth(damage_);
        }
    }
}
