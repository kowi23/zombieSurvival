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

    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("texture/player.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
    sf::Texture monsterTexture;
    if(!monsterTexture.loadFromFile("texture/monster.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
   Player player(playerTexture);


   std::vector<Bullet> bullets;
   std::vector<Monster> monsters;
   for (int i = 0; i < 5; i++){
       monsters.emplace_back(Monster(monsterTexture));

   }

    //// run the program as long as the window is open
    while (window.isOpen()) {
        //clock
       // sf::Time elapsed = clock.restart();
        time = std::clock();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }
            sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
            player.moveing(mousePosition);
            player.shooting(time,bullets);

            for (auto it = bullets.begin(); it != bullets.end(); it++){

                it->moveing(time, bullets,it);
                if(it == bullets.end()){
                    break;
                }
            }
            for (int i = 0; i < monsters.size(); i++){
                monsters[i].moveing(player.getPosition());
            }


        // clear the window with black color
        window.clear(sf::Color::Yellow);

        // draw everything here...
        for(const auto &bullet : bullets) {
                window.draw(bullet);
            }
        for(const auto &monster : monsters) {
                window.draw(monster);
            }
        window.draw(player);

        // end the current frame
        window.display();
    }

    return 0;
}
