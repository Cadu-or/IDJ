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

void Face::Update(float dt){
    InputManager input = InputManager::GetInstance();
    if(input.MousePress(LEFT_MOUSE_BUTTON)){
        float x = input.GetMouseX()+Camera::pos.x;
        float y = input.GetMouseY()+Camera::pos.y;
        // std::cout << input.GetMouseX()+Camera::pos.x << std::endl;
        // std::cout << input.GetMouseY() << std::endl;
        // std::cout << Camera::pos.y << std::endl;
        if(associated.box.Contains(Vec2(x, y))){
            Damage(std::rand()%10 + 10);
        }
    }
}
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