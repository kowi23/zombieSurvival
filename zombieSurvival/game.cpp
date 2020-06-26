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
    std::cout<<"blad wczytywania tekstury player"<<std::endl;
    }

    if(!monsterTexture.loadFromFile("texture/monster.png")) {
    std::cout<<"blad wczytywania tekstury monster"<<std::endl;
    }

    if(!handgunTexture.loadFromFile("texture/handgun.png")) {
    std::cout<<"blad wczytywania tekstury handgun"<<std::endl;
    }

    if(!rifleTexture.loadFromFile("texture/rifle.png")) {
    std::cout<<"blad wczytywania tekstury rifle"<<std::endl;
    }

    if(!shotgunTexture.loadFromFile("texture/shotgun.png")) {
    std::cout<<"blad wczytywania tekstury shotgun"<<std::endl;
    }

    if(!sniperrifleTexture.loadFromFile("texture/sniperrifle.png")) {
    std::cout<<"blad wczytywania tekstury sniperrifle"<<std::endl;
    }

    if(!granadeTexture.loadFromFile("texture/granade.png")) {
    std::cout<<"blad wczytywania tekstury granade"<<std::endl;
    }
    if(!boomTexture.loadFromFile("texture/boom.png")) {
    std::cout<<"blad wczytywania tekstury boom"<<std::endl;
    }
    if(!itemTexture.loadFromFile("texture/item.png")) {
    std::cout<<"blad wczytywania tekstury item"<<std::endl;
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

    granade.setTexture(granadeTexture);
    granade.setPosition(600,windowHight-75);

    background.setSize({windowWidth,75});
    background.setFillColor(sf::Color(230, 230, 230));
    background.setPosition(0,windowHight-75);
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(1);

    weapondBackground.setSize({150,75});
    weapondBackground.setFillColor(sf::Color::White);
    weapondBackground.setPosition(0,windowHight-75);

    blockBackground.setSize({150,75});
    blockBackground.setFillColor(sf::Color(100, 100, 100));

    playerHP.setFont(font);
    playerHP.setCharacterSize(40);
    playerHP.setString("1000 HP");
    playerHP.setColor(sf::Color::Black);
    playerHP.setPosition(800,windowHight-50);

    levelStr.setFont(font);
    levelStr.setCharacterSize(30);
    levelStr.setString("Lvl: 1");
    levelStr.setColor(sf::Color::Black);
    levelStr.setPosition(800,windowHight-80);

    granadeStr.setFont(font);
    granadeStr.setCharacterSize(22);
    granadeStr.setString("1");
    granadeStr.setColor(sf::Color::Black);
    granadeStr.setPosition(630,windowHight-70);

    ///MAIN MENU CREATE
    //logo
        logo.setFont(font);
        logo.setString("ZOMBIE SURVIVAL");
        logo.setCharacterSize(140);
        logo.setStyle(sf::Text::Bold);
        logo.setColor(sf::Color::Blue);
        logo.setPosition(80,100);
    //start game button
        startButton.setSize({300,80});
        startButton.setFillColor(sf::Color::White);
        startButton.setOrigin(150,40);
        startButton.setPosition(700, 400);
        startButton.setOutlineColor(sf::Color::White);
    //start string
        startStr.setFont(font);
        startStr.setString("Start Game");
        startStr.setCharacterSize(50);
        startStr.setStyle(sf::Text::Bold);
        startStr.setColor(sf::Color::Black);
        startStr.setOrigin(130,30);
        startStr.setPosition(700,400);
    //options button
        optionsButton.setSize({230,80});
        optionsButton.setFillColor(sf::Color::White);
        optionsButton.setOrigin(115,40);
        optionsButton.setPosition(700, 550);
        optionsButton.setOutlineColor(sf::Color::White);
    //options string
        optionsStr.setFont(font);
        optionsStr.setString("Options");
        optionsStr.setCharacterSize(50);
        optionsStr.setStyle(sf::Text::Bold);
        optionsStr.setColor(sf::Color::Black);
        optionsStr.setOrigin(95,30);
        optionsStr.setPosition(700,550);
    //exit button
        exitButton.setSize({130,80});
        exitButton.setFillColor(sf::Color::White);
        exitButton.setOrigin(65,40);
        exitButton.setPosition(700, 700);
        exitButton.setOutlineColor(sf::Color::White);
    //exit string
        exitStr.setFont(font);
        exitStr.setString("Exit");
        exitStr.setCharacterSize(50);
        exitStr.setStyle(sf::Text::Bold);
        exitStr.setColor(sf::Color::Black);
        exitStr.setOrigin(45,30);
        exitStr.setPosition(700,700);

   ////OPTIONS CREATE
        //BACK button
            backButton.setSize({150,80});
            backButton.setFillColor(sf::Color::White);
            backButton.setOrigin(75,40);
            backButton.setPosition(245, 700);
            backButton.setOutlineColor(sf::Color::White);
        //back string
            backStr.setFont(font);
            backStr.setString("Back");
            backStr.setCharacterSize(50);
            backStr.setStyle(sf::Text::Bold);
            backStr.setColor(sf::Color::Black);
            backStr.setOrigin(60,30);
            backStr.setPosition(245,700);
         //difficult button
            difficultButton.setSize({220,80});
            difficultButton.setFillColor(sf::Color::White);
            difficultButton.setOrigin(110,40);
            difficultButton.setPosition(280, 550);
            difficultButton.setOutlineColor(sf::Color::White);
        //difficult string
            difficultStr.setFont(font);
            difficultStr.setString("Difficult");
            difficultStr.setCharacterSize(50);
            difficultStr.setStyle(sf::Text::Bold);
            difficultStr.setColor(sf::Color::Black);
            difficultStr.setOrigin(95,30);
            difficultStr.setPosition(280,550);

            ////difficult balls
            b1.setRadius(25);
            b1.setFillColor(sf::Color::White);
            b1.setOrigin(25,25);
            b1.setOutlineColor(sf::Color::White);
            b1.setOutlineThickness(5);
            b1.setPosition(435, 550);

            b2.setRadius(25);
            b2.setFillColor(sf::Color::White);
            b2.setOrigin(25,25);
            b2.setOutlineColor(sf::Color::White);
            b2.setOutlineThickness(5);
            b2.setPosition(505, 550);

            b3.setRadius(25);
            b3.setFillColor(sf::Color::Black);
            b3.setOrigin(25,25);
            b3.setOutlineColor(sf::Color::White);
            b3.setOutlineThickness(5);
            b3.setPosition(575, 550);

      //END CREATE
            endBackground.setSize({1400,900});
            endBackground.setFillColor(sf::Color(0,0,0,180));
            endBackground.setPosition(0, 0);

            endStr.setPosition(700,450);
            endStr.setFont(font);
            endStr.setCharacterSize(100);
            endStr.setStyle(sf::Text::Bold);
            endStr.setColor(sf::Color::Yellow);

}

void Game::drawGame(){
    ///CLEAR
    window.clear(sf::Color::White);
    ///STRING UPDATE
    playerHP.setString(std::to_string(player.getHealth())+" HP");
    granadeStr.setString(std::to_string(player.getGranadeNum()));
    ///DRAW
    for(const auto &boom : booms) {
    window.draw(boom);
    }
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
    ///ZABLOKOWANA BRON
    std::set<itemType> availableWeaponds = player.availableWeaponds();
    if(availableWeaponds.find(itemType::Rifle) == availableWeaponds.end()){
        blockBackground.setPosition(150,windowHight-75);
        window.draw(blockBackground);
    }
    if(availableWeaponds.find(itemType::Shotgun) == availableWeaponds.end()){
        blockBackground.setPosition(300,windowHight-75);
        window.draw(blockBackground);
    }
    if(availableWeaponds.find(itemType::SniperRifle) == availableWeaponds.end()){
        blockBackground.setPosition(450,windowHight-75);
        window.draw(blockBackground);
    }
    window.draw(weapondBackground);
    window.draw(playerHP);
    window.draw(levelStr);
    window.draw(granadeStr);
    window.draw(handgun);
    window.draw(rifle);
    window.draw(shotgun);
    window.draw(sniperrifle);
    window.draw(granade);
}

void Game::drawMenu(){
    ///CLEAR
    window.clear(sf::Color::Black);
    //DRAW
    window.draw(logo);
    window.draw(startButton);
    window.draw(startStr);
    window.draw(optionsButton);
    window.draw(optionsStr);
    window.draw(exitButton);
    window.draw(exitStr);
}

void Game::optionsAnimation(){
    ///MOUSE POS
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    ///EVENT
    sf::Event event;
    while (window.pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed){
            window.close();
         }
        ///changing difficult level
        if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left){
                if(mousePos.x>170 && mousePos.x<390 && mousePos.y<590  && mousePos.y>510){
                    if(difficultLevel == 1){
                        difficultLevel = 2;
                        b2.setFillColor(sf::Color::White);
                    }else if(difficultLevel == 2){
                        difficultLevel = 3;
                        b3.setFillColor(sf::Color::White);
                    }else{
                        difficultLevel = 1;
                        b2.setFillColor(sf::Color::Black);
                        b3.setFillColor(sf::Color::Black);
                    }
                }
            }
        }
     }
    ////RESET BUTTONS
    backStr.setColor(sf::Color::Black);
    backButton.setFillColor(sf::Color::White);
    backButton.setOutlineThickness(0);
    difficultStr.setColor(sf::Color::Black);
    difficultButton.setFillColor(sf::Color::White);
    difficultButton.setOutlineThickness(0);



    ///BACK BUTTON
    if(mousePos.x>170 && mousePos.x<320 && mousePos.y<740  && mousePos.y>660){
            backStr.setColor(sf::Color::White);
            backButton.setFillColor(sf::Color::Black);
            backButton.setOutlineThickness(5);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
               state = State::Menu;
            }
     }
    /////////difficult BUTTON color swap
    if(mousePos.x>170 && mousePos.x<390 && mousePos.y<590  && mousePos.y>510){
         difficultStr.setColor(sf::Color::White);
         difficultButton.setFillColor(sf::Color::Black);
         difficultButton.setOutlineThickness(5);
    }
}

void Game::drawOptions(){
    ///CLEAR
    window.clear(sf::Color::Black);
    //DRAW
    window.draw(backButton);
    window.draw(backStr);
    window.draw(difficultButton);
    window.draw(difficultStr);
    window.draw(b1);
    window.draw(b2);
    window.draw(b3);
}

void Game::drawEnd(){

    drawGame();
    window.draw(endBackground);
    window.draw(endStr);

}

void Game::menuAnimation(){
    ///EVENT
    sf::Event event;
    while (window.pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed){
            window.close();
         }
     }
    ////RESET BUTTONS
    startStr.setColor(sf::Color::Black);
    startButton.setFillColor(sf::Color::White);
    startButton.setOutlineThickness(0);
    optionsStr.setColor(sf::Color::Black);
    optionsButton.setFillColor(sf::Color::White);
    optionsButton.setOutlineThickness(0);
    exitStr.setColor(sf::Color::Black);
    exitStr.setColor(sf::Color::Black);
    exitButton.setFillColor(sf::Color::White);
    exitButton.setOutlineThickness(0);

    ///MOUSE POS
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    ///START BUTTON
    if(mousePos.x>550 && mousePos.x<850 && mousePos.y<440  && mousePos.y>360){
        startStr.setColor(sf::Color::White);
        startButton.setFillColor(sf::Color::Black);
        startButton.setOutlineThickness(5);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(difficultLevel == 3){
                    player.setSpeed(3.5);
                }else{
                    player.setSpeed(2.5);
                }
                state = State::Game;
        }
     }
    /////////OPTIONS BUTTON
        if(mousePos.x>585 && mousePos.x<815 && mousePos.y<590  && mousePos.y>510){
            optionsStr.setColor(sf::Color::White);
            optionsButton.setFillColor(sf::Color::Black);
            optionsButton.setOutlineThickness(5);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                state = State::Options;
            }
        }
    ///EXIT BUTTON
    if(mousePos.x>635 && mousePos.x<765 && mousePos.y<740  && mousePos.y>660){
                        exitStr.setColor(sf::Color::White);
                        exitButton.setFillColor(sf::Color::Black);
                        exitButton.setOutlineThickness(5);
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                            window.close();
                        }

                    }
}

void Game::eventsGame(){
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

void Game::endAnimation(){
    ///EVENT
    sf::Event event;
    while (window.pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed){
            window.close();
         }
     }
    ///endTimer
    static int timer = time;
    if(time-timer>5000){
        window.close();
    }
}

void Game::gameAnimation(){
        ////animacja gracza
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        player.moveing(mousePosition);
        player.shooting(time,bullets,weapondBackground);

        ///kolizja gracz-przedmiot
        for (int i = 0; i < items.size(); i++){
            if(player.itemContact(items[i].getGlobalBounds(),items[i].getType())){
                items.erase(items.begin()+i);
            }
        }

       ///animacja pociskow
        for (int i = 0; i < bullets.size(); i++){
            bullets[i].moveing(time, bullets, i, monsters, booms, boomTexture);
        }
        ///animacja wybuchu
        for (int i = 0; i < booms.size(); i++){
            if(booms[i].animate(time)){
                booms.erase(booms.begin()+i);
            }
        }
        ///animacja potworow
        for (int i = 0; i < monsters.size(); i++){
            monsters[i].moveing(player.getPosition(), monsters, i);
            if(monsters[i].isBiting()){
                player.subtractHealth(monsters[i].getStrength()/3);

            }

        }

        //sprawdzanie konca gry
        if(player.getHealth()<1){
            endStr.setString("Game Over!");
            endStr.setOrigin(250,100);
            state = State::End;
        }
        if(level > 10){
            endStr.setString("You Win!");
            endStr.setOrigin(200,100);
            state = State::End;
        }
}

///spawn zombies, hp regeneration, levels, create items
void Game::oneSecCounter(){

    if(time-timer>1000){
        timer = time;
        if(player.getHealth()<1000){
            player.subtractHealth(-2);
        }
        if(monsters.empty()){
            counter = 0;
            level++;
            levelStr.setString("Lvl: " + std::to_string(level));
        }
        ///LEVELS
        if(counter < 4 && level == 1){
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 1.5,(std::rand() % 6)+9, (std::rand() % 21)+90,difficultLevel));
        }
        if(counter < 5 && level == 2){
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 1.5,(std::rand() % 6)+12, (std::rand() % 21)+90,difficultLevel));
        }
        if(counter < 2 && level == 3){
            //BOSS 1
            if(counter < 1){
                items.emplace_back(Item(itemTexture,itemType::Granade,sf::Vector2f((std::rand() % (windowWidth-50))+25,(std::rand() % (windowHight-125))+25)));
                monsters.emplace_back(Monster(monsterTexture, 1.3,(std::rand() % 6)+18, (std::rand() % 21)+490,difficultLevel));
            }
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 2.2,(std::rand() % 6)+6, (std::rand() % 21)+90,difficultLevel));
        }
        if(counter < 5 && level == 4){
            //rifle
            if(counter < 1){
                items.emplace_back(Item(itemTexture,itemType::Rifle,{windowWidth/2,windowHight/2-40}));
            }
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 2.2,(std::rand() % 6)+6, (std::rand() % 21)+90,difficultLevel));
        }
        if(counter < 4 && level == 5){
            //BOSS 2
            if(counter < 1){
                monsters.emplace_back(Monster(monsterTexture, 1.9,(std::rand() % 6)+24, (std::rand() % 21)+990,difficultLevel));
                items.emplace_back(Item(itemTexture,itemType::Granade,sf::Vector2f((std::rand() % (windowWidth-50))+25,(std::rand() % (windowHight-125))+25)));
            }
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 2.2,(std::rand() % 9)+6, (std::rand() % 21)+90,difficultLevel));
        }
        if(counter < 5 && level == 6){
            //shotgun
            if(counter < 1){
                items.emplace_back(Item(itemTexture,itemType::Shotgun,{windowWidth/2,windowHight/2-40}));
            }
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 2.2,(std::rand() % 12)+6, (std::rand() % 21)+240,difficultLevel));
        }
        if(counter < 10 && level == 7){
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 1.9,(std::rand() % 14)+6, (std::rand() % 21)+190,difficultLevel));
        }
        if(counter < 5 && level == 8){
            //BOSS 3
            if(counter < 1){
                monsters.emplace_back(Monster(monsterTexture, 1.3,(std::rand() % 6)+24, (std::rand() % 21)+2990,difficultLevel));
                items.emplace_back(Item(itemTexture,itemType::Granade,sf::Vector2f((std::rand() % (windowWidth-50))+25,(std::rand() % (windowHight-125))+25)));
            }
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 2.2,(std::rand() % 12)+6, (std::rand() % 21)+300,difficultLevel));
        }
        if(counter < 8 && level == 9){
            //sniperRifle
            if(counter < 1){
                items.emplace_back(Item(itemTexture,itemType::SniperRifle,{windowWidth/2,windowHight/2-40}));
            }
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 2.0,(std::rand() % 12)+6, (std::rand() % 21)+300,difficultLevel));
        }
        if(counter < 10 && level == 10){
            ///BOSS 4
            if(counter < 3){
                monsters.emplace_back(Monster(monsterTexture, 1.7,(std::rand() % 6)+24, (std::rand() % 21)+1990,difficultLevel));
            }
            counter ++;
            monsters.emplace_back(Monster(monsterTexture, 2.2,(std::rand() % 12)+6, (std::rand() % 21)+200,difficultLevel));
        }
        ///GENEROWANIE LOSOWYCH ITEMOW NA MAPIE
        switch ( std::rand() % 61 )
          {
             case 0:
                items.emplace_back(Item(itemTexture,itemType::Health,sf::Vector2f((std::rand() % (windowWidth-50))+25,(std::rand() % (windowHight-125))+25)));
                break;
             case 1:
             case 2:
             case 3:
                items.emplace_back(Item(itemTexture,itemType::Granade,sf::Vector2f((std::rand() % (windowWidth-50))+25,(std::rand() % (windowHight-125))+25)));
                break;
             default:
                break;
          }


    }
}


void Game::mainLoop(){
    while (window.isOpen()) {

       //clock
       time = std::clock();

       switch ( state )
         {
            case State::Game:
               eventsGame();
               gameAnimation();
               oneSecCounter();
               drawGame();
               break;
            case State::Menu:
               menuAnimation();
               drawMenu();
               break;
            case State::Options:
                optionsAnimation();
                drawOptions();
               break;
           case State::End:
               endAnimation();
               drawEnd();
               break;
            default:
               break;
         }

        window.display();
    }
}
