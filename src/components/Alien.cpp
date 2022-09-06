#include "../include/Alien.h"
#include "../include/Game.h"

Alien::Alien(GameObject& associated, int nMinions) : Component(associated){
    Sprite* sp = new Sprite(associated, "./src/resources/img/alien.png");
    associated.AddComponent(sp);
    hp = 30;
    speed = Vec2(0,0);
    this->nMinions = nMinions;
}

Alien::Action::Action(ActionType type, float x, float y){
    pos.x = x;
    pos.y = y;
    this->type = type;
}

void Alien::Start(){
    srand(time(NULL));
    for(int i = 0; i < nMinions; i++){
        GameObject* mgo = new GameObject();
        Minion* minion = new Minion(*mgo, Game::GetInstance().GetState().GetObjectPtr(&associated), ((i*M_PI)/3));
        mgo->AddComponent(minion);
        minionArray.push_back(Game::GetInstance().GetState().AddObject(mgo));
    }
}

Alien::~Alien(){}

void Alien::Update(float dt){
    InputManager im = InputManager::GetInstance();
    associated.angleDeg -= 360*dt/M_PI;
    if(im.MousePress(SDL_BUTTON_LEFT)){
        Action act = Action(Action::ActionType::SHOOT, im.GetMouseX()+Camera::pos.x, im.GetMouseY()+Camera::pos.y);
        taskQueue.push(act);

    }else if(im.MousePress(SDL_BUTTON_RIGHT)){
        Action act = Action((Action::ActionType::MOVE), im.GetMouseX()+Camera::pos.x, im.GetMouseY()+Camera::pos.y);
        taskQueue.push(act);
    }

    if(taskQueue.size() >= 1){
        if(taskQueue.front().type == Action::ActionType::MOVE){
            Vec2 point;
            point.x = taskQueue.front().pos.x - associated.box.w/2;
            point.y = taskQueue.front().pos.y - associated.box.h/2;
            Vec2 position = Vec2(associated.box.x, associated.box.y); //Posicao do alien
            speed = Vec2(0,0);
            speed = speed + (point - position).Normal();
            position = position + speed*dt*100;

            if(position.Distance(point) <= 3){
                position = point;
                taskQueue.pop();
            }

            associated.box.x = position.x;
            associated.box.y = position.y;
        }

        if(taskQueue.front().type == Action::ActionType::SHOOT){
            int dist_max = 99999999;

            std::weak_ptr<GameObject> cM;

            for(int i = 0; i < minionArray.size(); i++){
                float dist = minionArray[i].lock()->box.CoordCenter().Distance(taskQueue.front().pos);

                if(dist < dist_max){
                    dist_max = dist;
                    cM = minionArray[i];
                }

            }
            
            std::shared_ptr<GameObject> obj = cM.lock();

            Minion* minion = (Minion*)obj->GetComponent("Minion");
            minion->Shoot(taskQueue.front().pos);
            taskQueue.pop();
        }
    }
}

void Alien::Render(){}

bool Alien::Is(std::string type){
    return (type == "Alien" ? true : false);
}