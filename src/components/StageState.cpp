#include "../include/StageState.h"
#include "../include/Game.h"
#include "Collision.cpp"
#include <math.h>

StageState::StageState() : State(){
    quitRequested = false;
    started = false;
    
    GameObject* obj = new GameObject();
    Sprite *bg = new Sprite(*obj, "./src/resources/img/ocean.jpg");
    obj->AddComponent(bg);

	CameraFollower *CF = new CameraFollower(*obj);
	obj->AddComponent(CF);
    obj->box.x = Camera::pos.x;
    obj->box.y = Camera::pos.y;
    objectarray.emplace_back(obj);


	GameObject* obj2 = new GameObject();
	TileSet* tileset = new TileSet(64,64, "./src/resources/img/tileset.png");
    TileMap* tilemap = new TileMap(*obj2, "./src/resources/map/tileMap.txt", tileset);
	obj->AddComponent(tilemap);
	obj->box.x = 0;
	obj->box.y = 0;
	objectarray.emplace_back(obj2);


    for(int i = 0; i < 2; i++){
        GameObject* aobj = new GameObject();
        aobj->box.x = rand()%1000 - aobj->box.w/2;
        aobj->box.y = rand()%1000 - aobj->box.h/2;

        std::cout << aobj->box.x << std::endl;
        std::cout << aobj->box.y << std::endl;

        Alien* alien = new Alien(*aobj, 6, (float)(rand()%4/(rand()%1 + 0.3)));
        aobj->AddComponent(alien);

        objectarray.emplace_back(aobj);
    }

    backgroundMusic = new Music("./src/resources/audio/stageState.ogg");

    GameObject* penObj = new GameObject();
    penObj->box.x = 640 - penObj->box.w/2;
    penObj->box.y = 704 - penObj->box.h/2;
    PenguinBody* penbody = new PenguinBody(*penObj);
    penObj->AddComponent(penbody);

    Camera::Follow(penObj);

    objectarray.emplace_back(penObj);

    backgroundMusic->Play();
    quitRequested = false;
    started = false;
}

void StageState::Update(float dt){
    InputManager input = InputManager::GetInstance();
    if(input.KeyPress(SDLK_m) or PenguinBody::player == nullptr){
        GameData::playerVictory = false;
        popRequested = true;
        Game::GetInstance().Push(new EndState());

    }else if(input.KeyPress(SDLK_l)){
        GameData::playerVictory = true;
        popRequested = true;
        Game::GetInstance().Push(new EndState());
    }

    if(input.KeyPress(ESCAPE_KEY) or input.QuitRequested()){
        quitRequested = true;
    }

	Camera::Update(dt);

	UpdateArray(dt);

    for(int i = 0; i < objectarray.size(); i++){
        GameObject& obj1 = *objectarray[i];
        Collider* col1 = (Collider*)obj1.GetComponent("Collider");

        if(col1 != nullptr){
            for(int j = i + 1; j < objectarray.size(); j++){
                GameObject& obj2 = *objectarray[j];
                Collider* col2 = (Collider*)obj2.GetComponent("Collider");

                if(col2 != nullptr){
                    if(Collision::IsColliding(obj1.box, obj2.box, obj1.angleDeg, obj2.angleDeg)){
                        objectarray[i]->NotifyCollision(*objectarray[j]);
                        objectarray[j]->NotifyCollision(*objectarray[i]);
                    }
                }
            }
        }
    }

    for(int i = objectarray.size()-1; i >= 0; i--){
        if(objectarray[i]->IsDead()){
            std::cout << "passou" << std::endl;           
            objectarray.erase(objectarray.begin() + i);
        }
    }
}

void StageState::Render(){
    RenderArray();
}

bool StageState::QuitRequested(){
    return quitRequested;
}

StageState::~StageState(){
    objectarray.clear();
}

void StageState::LoadAssets(){}

void StageState::Start(){
    LoadAssets();
    StartArray();
    started = true;
}

void StageState::Resume(){}
void StageState::Pause(){}