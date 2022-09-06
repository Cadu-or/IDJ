#include "../include/Bullet.h"

Bullet::Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, std::string sprite) : Component(associated){
    Sprite *sp = new Sprite(associated, sprite);
    associated.AddComponent(sp);
    this->speed.x = Vec2(speed, 0).GetRotated(angle).x;
    this->speed.y = Vec2(speed, 0).GetRotated(angle).y;
    distanceLeft = maxDistance;
    this->damage = damage;

}

void Bullet::Update(float dt){
    Vec2 bullet = Vec2(associated.box.x, associated.box.y);

    bullet = (speed*dt) + bullet;
    associated.box.x = bullet.x;
    associated.box.y = bullet.y;

    distanceLeft = distanceLeft - (speed*dt).Magnitude();

    if(distanceLeft <= 0){
        associated.RequestDelete();
    }
}

void Bullet::Render(){}

bool Bullet::Is(std::string type){
    return (type == "Bullet" ? true : false);
}

int Bullet::GetDamage(){
    return damage;
}

void Bullet::Start(){}