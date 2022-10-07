#include "../include/TitleState.h"
#include "../include/Game.h"

TitleState::TitleState() : State(){
    GameObject* obj = new GameObject();
    Sprite* sp = new Sprite(*obj, "./src/resources/img/title.jpg");
    obj->box.x = 0;
    obj->box.y = 0;
    obj->AddComponent(sp);
    objectarray.emplace_back(obj);

    GameObject* obj2 = new GameObject();
    Text* text = new Text(*obj2, "./src/resources/font/Call me maybe.ttf", 20, Text::SOLID, "Pressione  I ESPACO I  para iniciar", {0,0,0,255});
    obj2->AddComponent(text);
    obj2->box.x = 340;
    obj2->box.y = 520;
    objectarray.emplace_back(obj2);

}

void TitleState::Update(float dt){
    InputManager input = InputManager::GetInstance();
    if(input.KeyPress(ESCAPE_KEY) or input.QuitRequested()){
        quitRequested = true;
    }

    if(input.KeyPress(SDLK_SPACE)){
        Game::GetInstance().Push(new StageState());
    }
}

void TitleState::Render(){
    RenderArray();
}

void TitleState::Start(){
    LoadAssets();
    StartArray();
}

TitleState::~TitleState(){}

void TitleState::LoadAssets(){}

void TitleState::Pause(){}

void TitleState::Resume(){}