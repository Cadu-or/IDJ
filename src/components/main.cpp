#include "../include/Game.h"

int main(int argc, char** argv){
    srand(time(NULL));
    Game game = Game::GetInstance();
    game.Run();

    return 0;
}