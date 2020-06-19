#include "game.hpp"


Game::Game():
window(sf::VideoMode(windowWidth, windowHight), "My window")
{
    window.setFramerateLimit(30);
}


void Game::loadTextures(){
    ///FONT
    font.loadFromFile("texture/sansation.ttf");
    ///TEXTURES

    if(!playerTexture.loadFromFile("texture/player.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }

    if(!monsterTexture.loadFromFile("texture/monster.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }

    if(!handgunTexture.loadFromFile("texture/handgun.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }

    if(!rifleTexture.loadFromFile("texture/rifle.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }

    if(!shotgunTexture.loadFromFile("texture/shotgun.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }

    if(!sniperrifleTexture.loadFromFile("texture/sniperrifle.png")) {
    std::cout<<"blad wczytywania tekstury gracza"<<std::endl;
    }
}

void Game::createObjects(){

    ///PLAYER CREATE
    player.setTexture(playerTexture);

    ///WEAPOND MENU CREATE

    handgun.setTexture(handgunTexture);
    handgun.setPosition(0,windowHight-75);
    //weapondsMenu.emplace_back(handgun);

    rifle.setTexture(rifleTexture);
    rifle.setPosition(150,windowHight-75);
    //weapondsMenu.emplace_back(rifle);

    shotgun.setTexture(shotgunTexture);
    shotgun.setPosition(300,windowHight-75);
    //weapondsMenu.emplace_back(shotgun);

    sniperrifle.setTexture(sniperrifleTexture);
    sniperrifle.setPosition(450,windowHight-75);
    //weapondsMenu.emplace_back(sniperrifle);


    background.setSize({windowWidth,75});
    background.setFillColor(sf::Color(230, 230, 230));
    background.setPosition(0,windowHight-75);
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(1);
    //weapondsMenu.emplace_back(background);

    weapondBackground.setSize({150,75});
    weapondBackground.setFillColor(sf::Color::White);
    weapondBackground.setPosition(0,windowHight-75);
    //weapondsMenu.emplace_back(weapondBackground);

    playerHP.setFont(font);
    playerHP.setCharacterSize(40);
    playerHP.setString("1000 HP");
    playerHP.setColor(sf::Color::Black);
    playerHP.setPosition(650,windowHight-50);
    //weapondsMenu.emplace("playerHP", playerHP);
}

void Game::drawAndDisplay(){
    ///CLEAR
    window.clear(sf::Color::White);

    ///DRAW
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
    window.draw(playerHP);
    window.draw(handgun);
    window.draw(rifle);
    window.draw(shotgun);
    window.draw(sniperrifle);

    ///DISPLAY
    window.display();
}
void Game::events(){
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
}
void Game::animation(){
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
                player.subtractHealth(monsters[i].getStrength()/3, playerHP);

            }

        }
}
void Game::mainLoop(){
    while (window.isOpen()) {

        //clock
        time = std::clock();

        events();

        animation();

        //zombie respawn
        if(time-timer>1000 && counter < 10){
            counter ++;
            timer = time;
            monsters.emplace_back(Monster(monsterTexture));
        }

        drawAndDisplay();
    }
}
