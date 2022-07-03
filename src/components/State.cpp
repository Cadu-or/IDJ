#include "../include/State.h"

State::State(){
    // std::cout << "STATE" << std::endl;
    bg = new Sprite("./src/resources/img/ocean.jpg");
    music = new Music("./src/resources/audio/stageState.ogg");

    music->Play();
    quitRequested = false;
}

void State::Update(float dt){
    if(SDL_QuitRequested()){
        quitRequested = true;
    }else{ 
        quitRequested = false;
    }
}

void State::Render(){
    bg->Render(0,0);
}

bool State::QuitRequested(){
    return quitRequested;
}
