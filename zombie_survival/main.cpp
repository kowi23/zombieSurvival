#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player : public sf::CircleShape {
public:
    std::string name() { return name_; }
    int size() { return size_; }
    double speed(){return speed_;};
    double max_speed() { return max_speed_; }

    Player(std::string name):name_(name){
        this->setRadius(size_);
        this->setPosition(400,300);
        this->setFillColor(sf::Color(100, 50, 250));

    }
    void animate(){
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
   Player player("mati");


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
