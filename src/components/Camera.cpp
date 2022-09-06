#include "../include/Camera.h"

Vec2 Camera::pos;
Vec2 Camera::speed;

GameObject* Camera::focus;

void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    InputManager input = InputManager::GetInstance();
    speed = Vec2(0,0);
    int aux = 100;

    if(focus != nullptr){
        pos.x = focus->box.CoordCenter().x-512;
        pos.y = focus->box.CoordCenter().y-300;
        
    }else{
        if(input.IsKeyDown(UP_ARROW_KEY)){
            speed = speed + Vec2(0,-1);
        }
        if(input.IsKeyDown(LEFT_ARROW_KEY)){
            speed = speed + Vec2(-1,0);
        }
        if(input.IsKeyDown(RIGHT_ARROW_KEY)){
            speed = speed + Vec2(1,0);
        }
        if(input.IsKeyDown(DOWN_ARROW_KEY)){
            speed = speed + Vec2(0,1);
        }

        pos = speed.Normal()*aux*dt + pos;
        // std::cout << "posx" << pos.x << std::endl;
        // std::cout << "posy" << pos.y << std::endl;
        // std::cout << "dt" << dt << std::endl;
    }
}