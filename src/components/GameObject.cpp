#include "../include/GameObject.h"

GameObject::GameObject(){
    isDead = false;
    started = false;
    angleDeg = 0;
}   

GameObject::~GameObject(){
    for(int i = components.size()-1; i >= 0; i--){
        components.erase(components.begin() + i);
    }
}

void GameObject::Update(float dt){
    for(int i = 0; i < components.size(); i++){
        components[i]->Update(dt);
    }
}

void GameObject::Render(){
    for(int i = 0; i < components.size(); i++){
        components[i]->Render();
    }
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.emplace_back(cpt);
    if(started == true){
        cpt->Start();
    }
}

void GameObject::RemoveComponent(Component* cpt){
    for(int i = 0; i < components.size(); i++){
        if(components[i].get() == cpt){
            components.erase(components.begin()+i);
            break;
        }
    }
}

Component* GameObject::GetComponent(std::string type){
    for(int i = 0; i < components.size(); i++){
        if(components[i]->Is(type)){
            return components[i].get();
        }
    }

    return nullptr;
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::Start(){
    for(int i = 0; i < components.size(); i++){
        components[i]->Start();
    }
    started = true;
}

void GameObject::NotifyCollision(GameObject& other){
    for(int i = 0; i < components.size(); i++){
        components[i]->NotifyCollision(other);
    }
}