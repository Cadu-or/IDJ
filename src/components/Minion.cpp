#include "../include/Minion.h"
#include "../include/Game.h"

Minion::Minion(GameObject& associated,std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg): Component(associated){
    Sprite* sp = new Sprite(associated, "./src/resources/img/minion.png");
    float scale = 1 + ((float)(rand()%50)/100);
    sp->SetScale(scale, scale);

    associated.AddComponent(sp);

    this->alienCenter = alienCenter;

    std::shared_ptr<GameObject> go = alienCenter.lock();
    associated.box.x = go->box.CoordCenter().x + 200 - associated.box.w/2;
    associated.box.y = go->box.CoordCenter().y + 0 - associated.box.h/2;
    
    arc = arcOffsetDeg;

    Collider* cll = new Collider(associated);
    associated.AddComponent(cll);
}

void Minion::Update(float dt){
    if(alienCenter.lock() == nullptr){
        associated.RequestDelete();
    }

    float cUpdate = M_PI/2*dt;

    Vec2 center = alienCenter.lock()->box.CoordCenter();
    Vec2 orMinion = Vec2(150, 0).GetRotated(arc)+center;

    associated.box.x = orMinion.x - associated.box.w/2;
    associated.box.y = orMinion.y - associated.box.h/2;
    arc = cUpdate + arc;

    associated.angleDeg = 180*arc/M_PI;
}

void Minion::Render(){}

bool Minion::Is(std::string type){
    return (type == "Minion" ? true : false);
}

void Minion::Shoot(Vec2 target){
    Vec2 dir = target - associated.box.CoordCenter();
    float angle = dir.InclX();

    GameObject* obj = new GameObject();
    Bullet* bullet = new Bullet(*obj, angle, 250, 10, 1024, "./src/resources/img/minionbullet2.png", 3, true);

    obj->box.x = associated.box.x;
    obj->box.y = associated.box.y;
    obj->angleDeg = angle*180/M_PI;

    obj->AddComponent(bullet);


    State *instance = &Game::GetInstance().GetCurrentState();
    instance->AddObject(obj);
}

Minion::~Minion(){}

void Minion::NotifyCollision(GameObject& other){}