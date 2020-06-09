#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {
public:
    std::string name() { return name_; }
    int size() { return size_; }
    double speed(){return speed_;};
    double max_speed() { return max_speed_; }

    Player(sf::Texture &texture_guy){
        this->setTexture(texture_guy);
        this->setOrigin(13,21);
        this->setPosition(400,300);

    }
    void animate(){
        //sf::Vector2i position = sf::Mouse::getPosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            this->move(0,-4);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            this->move(0,4);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            this->move(4,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            this->move(-4,0);
        }

    }
protected:

    std::string name_;
    int size_ = 12;
    double speed_;
    double max_speed_;
};



int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1400, 900), "My window");
    window.setFramerateLimit(60);
    // create some shapes
    sf::Texture texture_guy;
    if(!texture_guy.loadFromFile("player.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
   Player player(texture_guy);


    // run the program as long as the window is open
    while (window.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }
            player.animate();


        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(player);

        // end the current frame
        window.display();
    }

    return 0;
}
