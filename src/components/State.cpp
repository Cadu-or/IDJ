#include "../include/State.h"
#include <math.h>

State::State(){
    // std::cout << "STATE" << std::endl;
    GameObject* obj = new GameObject();
    bg = new Sprite(*obj, "./src/resources/img/ocean.jpg");
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


    music = new Music("./src/resources/audio/stageState.ogg");
    music->Play();
    quitRequested = false;
}

void State::Update(float dt){
    InputManager input = InputManager::GetInstance();
    if(input.KeyPress(ESCAPE_KEY) or input.QuitRequested()){
        quitRequested = true;
    }

    if(input.KeyPress(SDLK_SPACE)){
		Vec2 objPos = Vec2( 200, 0 ).GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 ) + Vec2(input.GetMouseX(), input.GetMouseY());
		AddObject((int)objPos.x, (int)objPos.y);
	}

	Camera::Update(dt);

	for(int i = 0; i < objectarray.size(); i++){
        objectarray[i]->Update(dt);
    }

    for(int i = 0; i < objectarray.size(); i++){
        if(objectarray[i]->IsDead()){
            objectarray.erase(objectarray.begin() + i);            
        }
    }
}

void State::Render(){
    for(int i = 0; i < objectarray.size(); i++){
        objectarray[i]->Render();
    }
}

bool State::QuitRequested(){
    return quitRequested;
}


void State::AddObject(int mouseX, int mouseY){
    GameObject* obj = new GameObject();
    Sprite* sp = new Sprite(*obj, "./src/resources/img/penguinface.png");

    obj->AddComponent(sp);
    obj->box.x = mouseX - obj->box.w + Camera::pos.x;
    obj->box.y = mouseY - obj->box.y + Camera::pos.y;

    Sound* snd = new Sound(*obj, "./src/resources/audio/boom.wav");
    obj->AddComponent(snd);

    Face* fc = new Face(*obj);
    obj->AddComponent(fc);

    objectarray.emplace_back(obj);

}

State::~State(){
    objectarray.clear();
}

void State::LoadAssets(){}