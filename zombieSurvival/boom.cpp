#include "boom.hpp"

Boom::Boom(sf::Texture &texture, clock_t time,  sf::Vector2f startPosition){
    this->setTexture(texture);///orginalnie 300x300
    this->setOrigin(150,150);
    this->setPosition(startPosition);
    startTime_ = time;
}
bool Boom::animate(clock_t time){
    if(time-startTime_>life_){
        return true;
    }else{
        return false;
    }
}
