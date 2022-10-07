#include "../include/PenguinBody.h"
#include "../include/PenguinCannon.h"
#include "../include/Game.h"

PenguinCannon::PenguinCannon(GameObject &associated, std::weak_ptr<GameObject> penguinbody) : Component(associated){
    angle = 0;
    pbody = penguinbody;
    Sprite* sp = new Sprite(associated, "./src/resources/img/cubngun.png");
    associated.AddComponent(sp);

    Collider* cll = new Collider(associated);
    associated.AddComponent(cll);

    timer = Timer();
    timer.Update(1);
}

void PenguinCannon::Update(float dt){
    timer.Update(dt);
    if(pbody.lock() == nullptr){
        associated.RequestDelete();
    }else{
        std::shared_ptr<GameObject> obj = pbody.lock();
        associated.box.x = obj->box.CoordCenter().x - associated.box.w/2;
        associated.box.y = obj->box.CoordCenter().y - associated.box.h/2;

        InputManager instance = InputManager::GetInstance();

        Vec2 cP = Vec2(instance.GetMouseX()+Camera::pos.x, instance.GetMouseY()+Camera::pos.y);
        Vec2 pos = associated.box.CoordCenter();
        angle = pos.InclXPoints(cP);
        associated.angleDeg = angle*180/M_PI;

        if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON) and timer.Get() > 0.5){
            Shoot();
            timer.Restart();
        }
    }
}

bool PenguinCannon::Is(std::string type){
    return (type == "PenguinCannon" ? true : false);
}

void PenguinCannon::Shoot(){
    Sprite* sp = (Sprite*)associated.GetComponent("Sprite");
    Vec2 pos = associated.box.CoordCenter();
    Vec2 aux = Vec2(sp->GetWidth()/2,0).GetRotated(angle)+pos;
    
    GameObject* obj = new GameObject();
    obj->box.x = aux.x;
    obj->box.y = aux.y;
    obj->angleDeg = angle*180/M_PI;

    Bullet* bullet = new Bullet(*obj, angle, 512, 10, 1024, "./src/resources/img/penguinbullet.png", 4, false);
    obj->AddComponent(bullet);

    State *instance = &Game::GetInstance().GetCurrentState();
    instance->AddObject(obj);
}

void PenguinCannon::Render(){}

void PenguinCannon::Start(){}

void PenguinCannon::NotifyCollision(GameObject& other){
}