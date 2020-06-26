#include "item.hpp"

itemType Item::getType(){return type_;}

Item::Item(sf::Texture &texture, itemType type, sf::Vector2f startPosition){
    type_ = type;
    this->setTexture(texture);
    this->setPosition(startPosition);
    if(type == itemType::Rifle ||type == itemType::Shotgun||type == itemType::SniperRifle){
        this->setScale(1.8,1.8);
    }
}
