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

Monster::Monster(sf::Texture &texture, float speed, int strength, int health, float difficultLevel){

    speed_ = speed*(difficultLevel/2);
    strength_ = strength;
    health_ = health*(difficultLevel/2);


    this->setTexture(texture);///orginalnie 30x30
    this->setScale(1/(15.f/strength_),1/(15.f/strength_));
    this->setOrigin(strength_,strength_);
    this->setPosition((std::rand() % 100)+650,-10);

}

void Monster::moveing(sf::Vector2f playerPosition, std::vector<Monster> &monsters, int index){

    sf::Vector2f monsterPosition = this->getPosition();

    float moveX = 0;
    float moveY = 0;

    ////OBROT I KAT W STRONE GRACZA
    angle_ = calculateAngle(monsterPosition,playerPosition);
    this->setRotation(angle_);
    ///ZWYKLY RUCH
    if(!biting_){
        //RUCH W STRONE GRACZA
        moveX = std::cos((angle_-90)*pi/180)*speed_;
        moveY = std::sin((angle_-90)*pi/180)*speed_;

    }else{
        moveX = (std::rand() % 3)-1;
        moveY = (std::rand() % 3)-1;
    }
    ///kolizja miedzy zombie
    for (int i = 0; i < monsters.size(); i++){
        if(i == index){continue;}
        sf::Vector2f monster2Position = monsters[i].getPosition();
        //kolizja
        if(cordsDistance(monsterPosition,monster2Position)<=strength_+monsters[i].getStrength()){
            angle_ = calculateAngle(monster2Position,monsterPosition);
            moveX = std::cos((angle_-45)*pi/180)*speed_;
            moveY = std::sin((angle_-45)*pi/180)*speed_;
            break;
        }
    }

    ///kolizja ze sciana
    if(monsterPosition.x<strength_ && moveX<0){
        moveX = 0;
    }
    if(monsterPosition.y<strength_ && moveY<0){
        moveY = 0;
    }
    if(monsterPosition.y>windowHight-75-strength_ && moveY>0){
        moveY = 0;
    }
    if(monsterPosition.x>windowWidth-strength_ && moveX>0){
        moveX = 0;
    }


    ///move
    this->move(moveX,moveY);
    ///kolizja z graczem
    if(cordsDistance(playerPosition,monsterPosition)<=strength_+constPlayerRadius){
        biting_ = true;
    }else{
        biting_ = false;
    }
}
