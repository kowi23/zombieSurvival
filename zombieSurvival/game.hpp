#ifndef game_hpp
#define game_hpp
#include <player.hpp>
#include <bullet.hpp>
#include <monster.hpp>

class Game{
public:
    Game();
    void loadTextures();
    void createObjects();
    void drawAndDisplay();
    void events();
    void animation();
    void zombieRespawn();
    void mainLoop();
private:
    sf::RenderWindow window;
    clock_t time;
    clock_t timer;
    int counter = 0;
    ///MAIN GAME OBJECTS
    Player player;
    std::vector<Bullet> bullets;
    std::vector<Monster> monsters;

    ///WEAPONDBAR
    sf::Sprite handgun;
    sf::Sprite rifle;
    sf::Sprite shotgun;
    sf::Sprite sniperrifle;
    sf::RectangleShape background;
    sf::RectangleShape weapondBackground;
    sf::Text playerHP;

    ///TEXTURES
    sf::Font font;
    sf::Texture shotgunTexture;
    sf::Texture sniperrifleTexture;
    sf::Texture rifleTexture;
    sf::Texture handgunTexture;
    sf::Texture monsterTexture;
    sf::Texture playerTexture;
};



#endif
