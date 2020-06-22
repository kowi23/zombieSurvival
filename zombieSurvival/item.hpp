#ifndef item_hpp
#define item_hpp

#include <myFunctions.hpp>

class Item : public sf::Sprite {
public:

    itemType getType();
    Item(sf::Texture &texture, itemType type, sf::Vector2f startPosition);

protected:
    itemType type_;
};
#endif
