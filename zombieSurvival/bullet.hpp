#ifndef bullet_hpp
#define bullet_hpp
#include <myFunctions.hpp>
#include <monster.hpp>
#include <boom.hpp>



class Bullet : public sf::CircleShape {
public:
    bool isGranade();
    Bullet(double angle, sf::Vector2f startPosition, clock_t time, int damage, int life);
    Bullet(double angle, sf::Vector2f startPosition,clock_t time);
    void hit(std::vector<Monster> &monsters, std::vector<Bullet> &bullets, int index);
    void moveing(clock_t time, std::vector<Bullet> &bullets, int index, std::vector<Monster> &monsters, std::vector<Boom> &booms, sf::Texture &boomTexture);
    void granadeBoom(std::vector<Monster> &monsters);
protected:
    int life_ = 1000;//bedzie zalezne od damage, w ms
    float speed_ = 20;
    float angle_;
    int damage_ = 40;
    int bulletRadius_ = 4;
    clock_t startTime_;
    bool isGranade_ = false;
};

#endif
