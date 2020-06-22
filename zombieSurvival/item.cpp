#include "item.hpp"

itemType Item::getType(){return type_;}

Item::Item(sf::Texture &texture, itemType type, sf::Vector2f startPosition){
    type_ = type;
    this->setTexture(texture);
    this->setPosition(startPosition);
}
