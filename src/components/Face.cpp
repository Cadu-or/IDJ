#include "../include/Face.h"

Face::Face(GameObject& associated) : Component(associated){
    Sethitpoints(30);
}

void Face::Damage(int damage){
    Sethitpoints(Gethitpoints() - damage);

    if(Gethitpoints() <= 0){
        associated.RequestDelete();
        Sound* snd = (Sound*)this->associated.GetComponent("Sound");
        if(snd != nullptr){
            snd->Play();
        }
    }
}

void Face::Update(float dt){}
void Face::Render(){}

bool Face::Is(std::string type){
    return (type == "Face" ? true : false);
}

void Face::Sethitpoints(int hitpoints){
    this->hitpoints = hitpoints;
}

int Face::Gethitpoints(){
    return hitpoints;
}