#include "../include/Vec2.h"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}

Vec2 Vec2::operator+(Vec2 vet){
    return Vec2(this->x + vet.x, this->y + vet.y);
}

Vec2 Vec2::operator-(Vec2 vet){
    return Vec2(this->x - vet.x, this->y - vet.y);
}

Vec2 Vec2::operator*(float escalar){
    return Vec2(this->x * escalar, this->y*escalar);
}

Vec2 Vec2::operator*(float const escalar) const{
    return Vec2(x*escalar, y*escalar);
}

float Vec2::Magnitude(){
    return sqrt((this->x * this->x) + (this->y * this->y));
}

Vec2 Vec2::Normal(){
    if(this->x != 0 and this->y != 0){
        return Vec2((this->x/(this->Magnitude())), this->y/(this->Magnitude()));
    }
    return *this;
}

float Vec2::Distance(Vec2 &vet){
    return ((*this - vet).Magnitude());
}

float Vec2::InclX(){
    return atan2(this->y, this->x);
}

float Vec2::InclXPoints(Vec2 &vet){
    Vec2 v = (*this - vet); 
    return atan2(v.y, v.x);
}

Vec2 Vec2::GetRotated(float ang){
    Vec2 v;
    v.x = ((this -> x * cos(ang)) - (this -> y * sin(ang)));
    v.y = ((this -> y * cos(ang)) + (this -> x * sin(ang)));
    return v;
}   