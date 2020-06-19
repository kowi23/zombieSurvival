
#include "game.hpp"




int main() {

    Game game;
    game.loadTextures();
    game.createObjects();

    game.mainLoop();

    return 0;
}
