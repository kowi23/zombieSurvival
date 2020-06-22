#include "monster.hpp"

int Monster::getStrength(){return strength_;}

void Monster::subtractHealth(int n,std::vector<Monster> &monsters, int index){
    health_ -= n;
    std::cout<<"Monster "<<index<<" HP: "<<health_<<std::endl;
    if(health_<=0){
        monsters.erase(monsters.begin()+index);
    }
}
bool Monster::isBiting(){
    return biting_ ;
}

Monster::Monster(sf::Texture &texture, float speed, int strength, int health){
    speed_ = speed;
    strength_ = strength;
    health_ = health;
    this->setTexture(texture);///orginalnie 30x30
    this->setScale(1/(15.f/strength_),1/(15.f/strength_));
    this->setOrigin(strength_,strength_);
    this->setPosition((std::rand() % 100)+650,-10);

}

void Monster::moveing(sf::Vector2f playerPosition, std::vector<Monster> &monsters, int index){

    sf::Vector2f monsterPosition = this->getPosition();

    ///kolizja miedzy zombie
    for (int i = 0; i < monsters.size(); i++){
        if(i == index){continue;}
        sf::Vector2f monster2Position = monsters[i].getPosition();
        //kolizja
        if(cordsDistance(monsterPosition,monster2Position)<=strength_+monsters[i].getStrength()){
            angle_ = calculateAngle(monster2Position,monsterPosition);
            this->move(std::cos((angle_-90)*pi/180)*speed_, std::sin((angle_-90)*pi/180)*speed_);
            break;
        }
    }
    if(!biting_){
        //zwykly ruch
        ////angle
        angle_ = calculateAngle(monsterPosition,playerPosition);
        //bez wykrywania scian
        this->move(std::cos((angle_-90)*pi/180)*speed_, std::sin((angle_-90)*pi/180)*speed_);
        /*
        ///wykrywanie scian
        float speedX = std::cos((angle-90)*pi/180)*speed;
        float speedY = std::sin((angle-90)*pi/180)*speed;
        if(monsterPosition.x>=windowWidth){
            if(speedX>0){
                std::cout<<"prawo"<<std::endl;
                speedX = 0;
            }
        }else if(monsterPosition.x<=0){
            if(speedX<0){
                std::cout<<"lewo"<<std::endl;
                speedX = 0;
            }
        }else if(monsterPosition.y>=windowHight-75){
            if(speedY>0){
                std::cout<<"dol"<<std::endl;
                speedY = 0;
            }
        }else if(monsterPosition.y<=0){
            std::cout<<"gora" <<speedY<<std::endl;
            if(speedY<0){
                std::cout<<"gora2"<<std::endl;
                speedY = 0;
            }
        }
        this->move(speedX,speedY);
        */

    }

    ////obrot
    this->setRotation(angle_);

    ///kolizja z graczem
    if(cordsDistance(playerPosition,monsterPosition)<=strength_+constPlayerRadius){

        biting_ = true;
    }else{
        biting_ = false;
    }
}
