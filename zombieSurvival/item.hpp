#ifndef item_hpp
#define item_hpp

#include <myFunctions.hpp>

class Item : public sf::Sprite {
public:

    Item(sf::Texture &texture, itemType type, sf::Vector2f startPosition);

        itemType getType();//zwraca typ przedmiotu

protected:
    itemType type_;
};
#endif
