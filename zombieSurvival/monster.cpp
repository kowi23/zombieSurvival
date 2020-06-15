#include "monster.hpp"

double Monster::getStrength(){return strength;}

void Monster::subtractHealth(int n,std::vector<Monster> &monsters, int index){
    health_ -= n;
    std::cout<<health_<<std::endl;
    if(health_<=0){
        monsters.erase(monsters.begin()+index);
    }
}
bool Monster::isBiting(){
    return biting_ ;
}

Monster::Monster(sf::Texture &texture){
    this->setTexture(texture);///orginalnie 30x30
    this->setScale(1/(15.f/strength),1/(15.f/strength));
    this->setOrigin(strength,strength);
    this->setPosition(700,-10);

}

void Monster::moveing(sf::Vector2f playerPosition, std::vector<Monster> &monsters, int index){

    sf::Vector2f monsterPosition = this->getPosition();

    ///kolizja miedzy zombie
    for (int i = 0; i < monsters.size(); i++){
        if(i == index){continue;}
        sf::Vector2f monster2Position = monsters[i].getPosition();
        //kolizja
        if(cordsDistance(monsterPosition,monster2Position)<=strength+monsters[i].getStrength()){
            angle = calculateAngle(monster2Position,monsterPosition);
            this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);
            break;
        }
    }
    if(!biting_){
        //zwykly ruch
        ////angle
        angle = calculateAngle(monsterPosition,playerPosition);
        this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);

    }

    ////obrot
    this->setRotation(angle);

    ///kolizja z graczem
    if(cordsDistance(playerPosition,monsterPosition)<=strength+constPlayerRadius){

        biting_ = true;
    }else{
        biting_ = false;
    }
}
