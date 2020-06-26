#ifndef boom_hpp
#define boom_hpp
#include <myFunctions.hpp>

class Boom : public sf::Sprite {
public:

    Boom(sf::Texture &texture, clock_t time,  sf::Vector2f startPosition);

    bool animate(clock_t time);//zwraca czy usunac obiekt/koniec animacji

protected:
    clock_t startTime_;
    int life_ = 300;//czas trwania
};
#endif
