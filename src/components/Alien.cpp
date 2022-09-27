#include "../include/Alien.h"
#include "../include/Game.h"

int Alien::alienCount = 0;

Alien::Alien(GameObject& associated, int nMinions) : Component(associated){
    Sprite* sp = new Sprite(associated, "./src/resources/img/alien.png");
    associated.AddComponent(sp);
    hp = 30;
    speed = Vec2(0,0);
    this->nMinions = nMinions;

    alienCount++;
    state = RESTING;
    restTimer = Timer();

    Collider* cll = new Collider(associated);
    associated.AddComponent(cll);
}

void Alien::Start(){
    for(int i = 0; i < nMinions; i++){
        GameObject* mgo = new GameObject();
        Minion* minion = new Minion(*mgo, Game::GetInstance().GetState().GetObjectPtr(&associated), ((i*M_PI)/3));
        mgo->AddComponent(minion);
        minionArray.push_back(Game::GetInstance().GetState().AddObject(mgo));
    }
}

Alien::~Alien(){
    for(int i = 0; i < minionArray.size(); i++){
        std::shared_ptr<GameObject> obj = minionArray[i].lock();
        obj->RequestDelete();
    }
    alienCount--;
}

void Alien::Update(float dt){
    associated.angleDeg -= M_PI/180*dt*256*8;
    Vec2 position = Vec2(associated.box.x, associated.box.y); //Posicao do alien

    restTimer.Update(dt);
    if(state == RESTING){
        if(restTimer.Get() > 0.5){
            Vec2 point;
            if(PenguinBody::player != nullptr){  
                point.x = PenguinBody::player->GetCenter().x - associated.box.w/2;
                point.y = PenguinBody::player->GetCenter().y - associated.box.h/2;
                destination = Vec2(point.x, point.y);
                speed = Vec2(0,0);
                speed = speed + (point - position).Normal();
                state = MOVING;
            }
        }
    }

    if(state == MOVING){
        bool close = false;
        position = position + speed*dt*100;

        if(std::abs(position.Distance(destination) <= 300)){
            close = true;
            speed = Vec2(0,0);
        }

        associated.box.x = position.x;
        associated.box.y = position.y;
        
        if(close){
            Vec2 dest;
            if(PenguinBody::player != nullptr){
                dest.x = PenguinBody::player->GetCenter().x;
                dest.y = PenguinBody::player->GetCenter().y;

                destination = Vec2(dest.x, dest.y);
                
                int dist_max = 99999999;
                std::weak_ptr<GameObject> cM;
                for(int i = 0; i < minionArray.size(); i++){
                    float dist = minionArray[i].lock()->box.CoordCenter().Distance(destination);

                    if(dist < dist_max){
                        dist_max = dist;
                        cM = minionArray[i];
                    }
                }

                std::shared_ptr<GameObject> obj = cM.lock();

                Minion* minion = (Minion*)obj->GetComponent("Minion");
                minion->Shoot(destination);

                state = RESTING;
                restTimer.Restart();
            }
        }
    }
}

void Alien::Render(){}

bool Alien::Is(std::string type){
    return (type == "Alien" ? true : false);
}

void Alien::NotifyCollision(GameObject& other){
    Bullet* bullet = (Bullet*) other.GetComponent("Bullet");
    if(bullet != nullptr){
        std::cout << "Houve Colisão Allien" << std::endl; 
    }
}