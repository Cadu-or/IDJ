#include "../include/State.h"

State::State(){
    quitRequested = false;
    started = false;
    popRequested = false;
}

State::~State(){
    objectarray.clear();
}

void State::LoadAssets(){}

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

bool State::QuitRequested(){
    return quitRequested;
}

bool State::PopRequested(){
    return popRequested;
}

void State::StartArray(){
    for(int i = 0; i < objectarray.size(); i++){
        objectarray[i]->Start();
    }
}

void State::UpdateArray(float dt){
    for(int i = 0; i < objectarray.size(); i++){
        objectarray[i]->Update(dt);
    }
}

void State::RenderArray(){
    for(int i = 0; i < objectarray.size(); i++){
        objectarray[i]->Render();
    }
}