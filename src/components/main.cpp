#include "../include/Game.h"
#include "../include/TitleState.h"

int main(int argc, char** argv){
    srand(time(NULL));
    Game::GetInstance().Push(new TitleState());
    Game::GetInstance().Run();

    return 0;
}