#include "monster.hpp"

double Monster::getStrength(){return strength;}

Monster::Monster(sf::Texture &texture){
    this->setTexture(texture);///orginalnie 30x30
    this->setScale(1/(15.f/strength),1/(15.f/strength));
    this->setOrigin(strength,strength);
    this->setPosition(700,-10);

}

void Monster::moveing(Player &player, std::vector<Monster> monsters, int index){
    bool isMonstersColl = false;
    sf::Vector2f monsterPosition = this->getPosition();
    sf::Vector2f playerPosition = player.getPosition();
    ///kolizja miedzy zombie
    for (int i = 0; i < monsters.size(); i++){
        if(i == index){continue;}
        sf::Vector2f monster2Position = monsters[i].getPosition();
        //kolizja
        if(cordsDistance(monsterPosition,monster2Position)<=strength+monsters[i].getStrength()){
            angle = calculateAngle(monster2Position,monsterPosition);
            this->move(std::cos((angle-90)*pi/180)*speed, std::sin((angle-90)*pi/180)*speed);
            isMonstersColl = true;
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
    if(cordsDistance(playerPosition,monsterPosition)<=strength+player.getRadius()){
        std::cout<<"bite"<<std::endl;
        biting_ = true;
    }else{
        biting_ = false;
    }
}
