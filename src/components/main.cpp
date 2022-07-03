#include "../include/Game.h"

int main(int argc, char** argv){
    Game *a = Game::GetInstance();
    a->Run();

    return 0;
}