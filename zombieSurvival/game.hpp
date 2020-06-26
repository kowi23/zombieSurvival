#ifndef game_hpp
#define game_hpp
#include <player.hpp>
#include <bullet.hpp>
#include <monster.hpp>
#include <item.hpp>

class Game{
public:
    Game();
    void loadTextures();
    void createObjects();
    void drawGame();
    void drawMenu();
    void menuAnimation();
    void eventsGame();
    void gameAnimation();
    void oneSecCounter();
    void mainLoop();
private:
    sf::RenderWindow window;
    clock_t time;
    clock_t timer;
    int counter = 0;
    int level = 0;
    State state = State::Menu;
    ///MAIN GAME OBJECTS
    Player player;
    std::vector<Bullet> bullets;
    std::vector<Monster> monsters;
    std::vector<Item> items;

    ///WEAPONDBAR
    sf::Sprite handgun;
    sf::Sprite rifle;
    sf::Sprite shotgun;
    sf::Sprite sniperrifle;
    sf::Sprite granade;
    sf::Sprite granadeBoom;
    sf::RectangleShape background;
    sf::RectangleShape weapondBackground;
    sf::Text playerHP;
    sf::Text levelStr;
    sf::Text granadeStr;

    ///MAIN MENU
    sf::Text logo;
    sf::RectangleShape startButton;
    sf::Text startStr;
    sf::Text optionsStr;
    sf::RectangleShape optionsButton;
    sf::Text exitStr;
    sf::RectangleShape exitButton;

    ///TEXTURES
    sf::Font font;
    sf::Texture shotgunTexture;
    sf::Texture sniperrifleTexture;
    sf::Texture rifleTexture;
    sf::Texture handgunTexture;
    sf::Texture granadeTexture;
    sf::Texture boomTexture;
    sf::Texture monsterTexture;
    sf::Texture playerTexture;
};



#endif
