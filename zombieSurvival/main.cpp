#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <bullet.hpp>

const float pi = M_PI;
const int windowHight = 900;
const int windowWidth = 1400;




int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHight), "My window");
    window.setFramerateLimit(60);
    sf::Clock clock;
    // create some shapes
    sf::Texture texture_guy;
    if(!texture_guy.loadFromFile("player.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
   Player player(texture_guy);


   //std::vector<Bullet> bullets;

    // run the program as long as the window is open
    while (window.isOpen()) {
        //clock
        sf::Time elapsed = clock.restart();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            player.moveing(mousePosition);
            player.shooting(elapsed);


        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(player);

        // end the current frame
        window.display();
    }

    return 0;
}
