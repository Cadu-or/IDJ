#include "../include/PenguinBody.h"
#include "../include/PenguinCannon.h"
#include "../include/Game.h"

PenguinBody* PenguinBody::player = nullptr;

PenguinBody::PenguinBody(GameObject &associated) : Component(associated){
    speed = Vec2(0,0);
    linearSpeed = 0.1;
    angle = 0;
    hp = 100;
    player = this;
    Sprite* sp = new Sprite(associated, "./src/resources/img/penguin.png");
    associated.AddComponent(sp);

    Collider* cll = new Collider(associated);
    associated.AddComponent(cll);
}

PenguinBody::~PenguinBody(){
    player = nullptr;
}

void PenguinBody::Start(){
    GameObject* obj = new GameObject(); 
    State* instance = &Game::GetInstance().GetCurrentState();

    std::weak_ptr<GameObject> penguin_ptr = instance->GetObjectPtr(&associated);
    PenguinCannon* pC = new PenguinCannon(*obj, penguin_ptr);
    obj->AddComponent(pC);
    penguin_ptr = instance->AddObject(obj);
}

void PenguinBody::Update(float dt){
    if(hp <= 0){
        Camera::Unfollow();

        GameObject* obj = new GameObject();
        State* instance = &Game::GetInstance().GetCurrentState();
        
        Sprite* sp = new Sprite(*obj, "./src/resources/img/penguindeath.png", 5, 0.1, 0.5);
        obj->box.x = associated.box.CoordCenter().x - obj->box.w/2;
        obj->box.y = associated.box.CoordCenter().y - obj->box.h/2;

        Sound* sd = new Sound(*obj, "./src/resources/audio/boom.wav");
        sd->Play();
        
        obj->AddComponent(sd);
        obj->AddComponent(sp);
        instance->AddObject(obj);

        associated.RequestDelete();
        player = nullptr;
    }

    InputManager instance = InputManager::GetInstance();
    if(instance.IsKeyDown(SDLK_w) and linearSpeed < 200){
        linearSpeed += 10;

    }else if(instance.IsKeyDown(SDLK_s) and linearSpeed > -200){
        linearSpeed -= 10;
    }

    if(instance.IsKeyDown(SDLK_a)){
        angle -= 1*dt;

    }else if(instance.IsKeyDown(SDLK_d)){
       angle += 1*dt;
    }

    speed = Vec2(linearSpeed, 0).GetRotated(angle);

    associated.angleDeg = angle*180/M_PI;

    Vec2 dest = speed*dt;

    associated.box.x += dest.x;
    associated.box.y += dest.y;

    if(associated.box.x > 1408){
        associated.box.x = 1408;
    }

    if(associated.box.x < 0){
        associated.box.x = 0;
    }

    if(associated.box.y > 1280){
        associated.box.y = 1280;
    }

    if(associated.box.y < 0){
        associated.box.y = 0;
    }
}

bool PenguinBody::Is(std::string type){
    return (type == "PenguinBody" ? true : false);
}

void PenguinBody::Render(){}

void PenguinBody::NotifyCollision(GameObject& other){
    Bullet* bull = (Bullet*)other.GetComponent("Bullet");
    if(bull != nullptr){
        if(bull->targetsPlayer){
            hp = hp - bull->GetDamage();
            std::cout << hp << std::endl;
            other.RequestDelete();
        }
    }
}

Vec2 PenguinBody::GetCenter(){
    return associated.box.CoordCenter();
}