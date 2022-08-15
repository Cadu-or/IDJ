#include "../include/Rect.h"

Rect::Rect(){
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
}

Rect::Rect(float x, float y, float w, float h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Rect Rect::operator+(Vec2 vet){
    return Rect(this->x + vet.x, this->y + vet.y, this->w, this->h);
}

Rect Rect::SumVec2(Vec2 vet, Rect rect){
    return Rect(rect.x + vet.x, rect.y + vet.y, rect.w, rect.h);
}

Vec2 Rect::CoordCenter(){
    return Vec2((this->x + this->w/2),(this->y + this->h/2));
}

bool Rect::Contains(Vec2 vet){
    try{
        ((vet.x > this -> x) and (vet.x < this -> x + this -> w)) ? NULL : throw 1;
        ((vet.y > this -> y) and (vet.y < this -> y + this -> h)) ? NULL : throw 1;
        return true;
    }catch(int num){
        return false;
    }
}
