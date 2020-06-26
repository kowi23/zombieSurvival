#ifndef game_hpp
#define game_hpp
#include <player.hpp>
#include <bullet.hpp>
#include <monster.hpp>
#include <item.hpp>
#include <boom.hpp>

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
    void optionsAnimation();
    void drawOptions();
private:
    int difficultLevel = 2;
    sf::RenderWindow window;
    clock_t time;
    clock_t timer = 0;
    int counter = 0;
    int level = 0;
    State state = State::Menu;
    ///MAIN GAME OBJECTS
    Player player;
    std::vector<Bullet> bullets;
    std::vector<Monster> monsters;
    std::vector<Item> items;
    std::vector<Boom> booms;
    sf::Sprite granadeBoom;

    ///WEAPONDBAR
    sf::Sprite handgun;
    sf::Sprite rifle;
    sf::Sprite shotgun;
    sf::Sprite sniperrifle;
    sf::Sprite granade;
    sf::RectangleShape background;
    sf::RectangleShape blockBackground;
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

    ///OPTIONS
    sf::RectangleShape backButton;
    sf::Text backStr;
    sf::RectangleShape difficultButton;
    sf::Text difficultStr;
    sf::CircleShape b1;
    sf::CircleShape b2;
    sf::CircleShape b3;

    ///TEXTURES
    sf::Font font;
    sf::Texture itemTexture;
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
