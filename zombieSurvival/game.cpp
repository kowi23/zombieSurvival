#include "game.hpp"


Game::Game():
window(sf::VideoMode(windowWidth, windowHight), "My window")
{
    window.setFramerateLimit(60);
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


    rifle.setTexture(rifleTexture);
    rifle.setPosition(150,windowHight-75);


    shotgun.setTexture(shotgunTexture);
    shotgun.setPosition(300,windowHight-75);


    sniperrifle.setTexture(sniperrifleTexture);
    sniperrifle.setPosition(450,windowHight-75);



    background.setSize({windowWidth,75});
    background.setFillColor(sf::Color(230, 230, 230));
    background.setPosition(0,windowHight-75);
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(1);


    weapondBackground.setSize({150,75});
    weapondBackground.setFillColor(sf::Color::White);
    weapondBackground.setPosition(0,windowHight-75);


    playerHP.setFont(font);
    playerHP.setCharacterSize(40);
    playerHP.setString("1000 HP");
    playerHP.setColor(sf::Color::Black);
    playerHP.setPosition(650,windowHight-50);

    levelStr.setFont(font);
    levelStr.setCharacterSize(30);
    levelStr.setString("Lvl: 1");
    levelStr.setColor(sf::Color::Black);
    levelStr.setPosition(650,windowHight-80);
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
    for(const auto &item : items) {
            window.draw(item);
        }

    window.draw(player);
    ///DRAW WEAPOND MENU
    window.draw(background);
    window.draw(weapondBackground);
    window.draw(playerHP);
    window.draw(levelStr);
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

        ///kolizja gracz-przedmiot
        for (int i = 0; i < items.size(); i++){
            if(player.itemContact(items[i].getGlobalBounds(),items[i].getType())){
                items.erase(items.begin()+i);
            }
        }

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
///spawn zombies, hp regeneration, levels, create items
void Game::oneSecCounter(){
    if(time-timer>1000){
        timer = time;
        if(player.getHealth()<1000){
            player.subtractHealth(-2, playerHP);
        }
        if(monsters.empty()){
            counter = 0;
            level++;
            levelStr.setString("Lvl: " + std::to_string(level));
        }
        ///levels
        if(counter < 2 && level == 1){
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 1.5,(std::rand() % 6)+9, (std::rand() % 21)+90));
        }
        if(counter < 3 && level == 2){
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 1.5,(std::rand() % 6)+9, (std::rand() % 21)+90));
        }
        if(counter < 1 && level == 3){
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 1.5,(std::rand() % 6)+9, (std::rand() % 21)+90));
        }
        if(level == 4){
            std::cout<<"Win!!!!!"<<std::endl;
        }
        switch ( std::rand() % 21 )
          {
             case 0:
                items.emplace_back(Item(playerTexture,itemType::health,sf::Vector2f((std::rand() % (windowWidth-50))+25,(std::rand() % (windowHight-125))+25)));
                break;
             case 1:
                items.emplace_back(Item(playerTexture,itemType::granade,sf::Vector2f((std::rand() % (windowWidth-50))+25,(std::rand() % (windowHight-125))+25)));
                break;
             default:
                break;
          }


    }
}
////Contains animation, events, drawAndDisplay and oneSecCounter
void Game::mainLoop(){
    while (window.isOpen()) {

        //clock
        time = std::clock();

        events();

        animation();

        oneSecCounter();

        drawAndDisplay();
    }
}
