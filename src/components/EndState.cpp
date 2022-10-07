#include "../include/EndState.h"
#include "../include/Game.h"

EndState::EndState() : State(){
    std::string spPath;
    std::string msPath;
    bool status = false;

    Camera::pos.x = 0;
    Camera::pos.y = 0;

    if(GameData::playerVictory){
        spPath = "./src/resources/img/win.jpg";
        msPath = "./src/resources/audio/endStateWin.ogg";
        status = true;
    }else{
        if(PenguinBody::player == nullptr){
            spPath = "./src/resources/img/lose.jpg";
            msPath = "./src/resources/audio/endStateLose.ogg";
            status = true;
        }
    }
    
    if(status){
        GameObject* obj = new GameObject();
        Sprite *bg = new Sprite(*obj, spPath);
        obj->box.x = 0;
        obj->box.y = 0;
        obj->AddComponent(bg);
        objectarray.emplace_back(obj);

        GameObject* obj2 = new GameObject();
        SDL_Color color = {0,0,0,255};
        Text *text = new Text(*obj2, "./src/resources/font/Call me maybe.ttf", 20, Text::BLENDED, "Pressione  I ESPACO I  para voltar ao menu ou  I ESC I  para sair", color);
        obj2->AddComponent(text);
        objectarray.emplace_back(obj2);
        obj2->box.x = 250;
        obj2->box.y = 20;

        backgroundMusic = new Music(msPath);
        backgroundMusic->Play();
    }

}

void EndState::Update(float dt){
    InputManager input = InputManager::GetInstance();
    if(input.KeyPress(ESCAPE_KEY) or input.QuitRequested()){
        quitRequested = true;
    }
    if(input.KeyPress(SDLK_SPACE)){
        popRequested = true;
        Game::GetInstance().Push(new TitleState());
    }
    UpdateArray(dt);
}

void EndState::Render(){
    Camera::pos = Vec2(0, 0);
    RenderArray();
}

EndState::~EndState(){
    objectarray.clear();
    backgroundMusic->Stop();
}

void EndState::LoadAssets(){}
void EndState::Start(){}
void EndState::Resume(){}
void EndState::Pause(){}