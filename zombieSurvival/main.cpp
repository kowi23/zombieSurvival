#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <bullet.hpp>
#include <monster.hpp>
#include <constants.hpp>




int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHight), "My window");
    window.setFramerateLimit(30);
    //sf::Clock clock;
    clock_t time;
    clock_t timer;
    //do spawnu zombie
    int counter = 0;

    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("texture/player.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
    sf::Texture monsterTexture;
    if(!monsterTexture.loadFromFile("texture/monster.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
    sf::Texture handgunTexture;
    if(!handgunTexture.loadFromFile("texture/handgun.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
    sf::Texture rifleTexture;
    if(!rifleTexture.loadFromFile("texture/rifle.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
    sf::Texture shotgunTexture;
    if(!shotgunTexture.loadFromFile("texture/shotgun.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
    sf::Texture sniperrifleTexture;
    if(!sniperrifleTexture.loadFromFile("texture/sniperrifle.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }

    ///STWORZENIE GRACZA
   Player player(playerTexture);
    ///STWORZENIE VEKTOROW
   std::vector<Bullet> bullets;
   std::vector<Monster> monsters;

    ///STWORZENIE MENU WYBORU BRONI
    sf::Sprite handgun = sf::Sprite();
    handgun.setTexture(handgunTexture);
    handgun.setPosition(0,windowHight-75);
    sf::Sprite rifle = sf::Sprite();
    rifle.setTexture(rifleTexture);
    rifle.setPosition(150,windowHight-75);
    sf::Sprite shotgun = sf::Sprite();
    shotgun.setTexture(shotgunTexture);
    shotgun.setPosition(300,windowHight-75);
    sf::Sprite sniperrifle = sf::Sprite();
    sniperrifle.setTexture(sniperrifleTexture);
    sniperrifle.setPosition(450,windowHight-75);
    sf::RectangleShape background = sf::RectangleShape({windowWidth,75});
    background.setFillColor(sf::Color(230, 230, 230));
    background.setPosition(0,windowHight-75);
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(1);
    sf::RectangleShape weapondBackground = sf::RectangleShape({150,75});
    weapondBackground.setFillColor(sf::Color::White);
    weapondBackground.setPosition(0,windowHight-75);
    ///
    ////GLOWNA PETLA GRY
    while (window.isOpen()) {
        //clock
       // sf::Time elapsed = clock.restart();
        time = std::clock();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
             }
            ///zmiana broni
            if (event.type == sf::Event::KeyPressed){
                player.changingWeapond(event, weapondBackground);
            }
         }
        ////animacja gracza
            sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
            player.moveing(mousePosition);
            player.shooting(time,bullets);

           ///animacja pociskow
            for (int i = 0; i < bullets.size(); i++){
                bullets[i].moveing(time, bullets, i);
                bullets[i].hit(monsters, bullets, i);
            }
            ///animacja potworow
            for (int i = 0; i < monsters.size(); i++){
                monsters[i].moveing(player.getPosition(), monsters, i);
                if(monsters[i].isBiting()){
                    player.subtractHealth(monsters[i].getStrength()/3);

                }

            }

            //zombie respawn
            if(time-timer>1000 && counter < 10){
                counter ++;
                timer = time;
                monsters.emplace_back(Monster(monsterTexture));
            }


        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        for(const auto &bullet : bullets) {
                window.draw(bullet);
            }
        for(const auto &monster : monsters) {
                window.draw(monster);
            }
        window.draw(player);
        ///DRAW WEAPOND MENU
        window.draw(background);
        window.draw(weapondBackground);
        window.draw(handgun);
        window.draw(rifle);
        window.draw(shotgun);
        window.draw(sniperrifle);


        // end the current frame
        window.display();
    }

    return 0;
}
