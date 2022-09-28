#include "../include/State.h"
#include "Collision.cpp"
#include <math.h>

State::State(){
    // std::cout << "STATE" << std::endl;
    started = false;
    
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


    GameObject* aobj = new GameObject();

    aobj->box.x = 300;
    aobj->box.y = 512;

    Alien* alien = new Alien(*aobj, 6);

    aobj->AddComponent(alien);    
    objectarray.emplace_back(aobj);

    music = new Music("./src/resources/audio/stageState.ogg");

    GameObject* penObj = new GameObject();
    penObj->box.x = 640 - penObj->box.w/2;
    penObj->box.y = 704 - penObj->box.h/2;
    PenguinBody* penbody = new PenguinBody(*penObj);
    penObj->AddComponent(penbody);

    Camera::Follow(penObj);

    objectarray.emplace_back(penObj);

    music->Play();
    quitRequested = false;
    started = false;
}

void State::Update(float dt){
    InputManager input = InputManager::GetInstance();
    if(input.KeyPress(ESCAPE_KEY) or input.QuitRequested()){
        quitRequested = true;
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

    for(int i = 0; i < objectarray.size(); i++){
        GameObject& obj1 = *objectarray[i];
        Collider* col1 = (Collider*)obj1.GetComponent("Collider");

        if(col1 != nullptr){
            for(int j = i + 1; j < objectarray.size(); j++){
                GameObject& obj2 = *objectarray[j];
                Collider* col2 = (Collider*)obj2.GetComponent("Collider");

                if(col2 != nullptr){
                    if(Collision::IsColliding(obj1.box, obj2.box, obj1.angleDeg*(M_PI/180), obj2.angleDeg*(M_PI/180))){
                        objectarray[i]->NotifyCollision(*objectarray[j]);
                        objectarray[j]->NotifyCollision(*objectarray[i]);
                    }
                }
            }
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

State::~State(){
    objectarray.clear();
}

void State::LoadAssets(){}

void State::Start(){
    LoadAssets();
    for(int i = 0; i < objectarray.size(); i++){
        objectarray[i].get()->Start();
    }
    started = true;
}

std::weak_ptr <GameObject> State::AddObject(GameObject* go){
    std::shared_ptr<GameObject> sobj(go);

    objectarray.push_back(sobj);

    if(started == true){
        sobj->Start();
    }

    std::weak_ptr <GameObject> wobj(sobj);

    return wobj;
}

std::weak_ptr <GameObject> State::GetObjectPtr(GameObject* go){
    for(int i = 0; i < objectarray.size(); i++){
        if(objectarray[i].get() == go){
            std::weak_ptr <GameObject> wobj(objectarray[i]);
            return wobj; 
        }
    }
    return{};
}