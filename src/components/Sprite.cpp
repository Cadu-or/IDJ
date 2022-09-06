#include "../include/Sprite.h"
#include "../include/Game.h"

Sprite::Sprite(GameObject& associated):Component(associated){
    texture = nullptr;
    SetScale(1, 1);
}

Sprite::Sprite(GameObject& associated, std::string file):Component(associated){
    // std::cout << "Sprite file: " << file << std::endl;
    texture = nullptr;
    SetScale(1, 1);
    Open(file);
}

Sprite::~Sprite(){
    // SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file){
    
    texture = Resources::GetImage(file);
    // std::cout << "TEXTURE: " << texture << std::endl;
    if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) != 0){
        std::cout << "ERROR: QueryTexture" << std::endl;
    }
    SetClip(0, 0, width, height);
    associated.box.w = width;
    associated.box.h = height;
    
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(){
    Render(associated.box.x-Camera::pos.x, associated.box.y-Camera::pos.y);
}

void Sprite::Render(float x, float y){
    SDL_Rect dst;
    dst.x = x + clipRect.w/2 - clipRect.w/2*GetScale().x;
    dst.y = y + clipRect.h/2 - clipRect.h/2*GetScale().y;
    dst.w = clipRect.w * this->GetScale().x;
    dst.h = clipRect.h * this->GetScale().y;

    if(SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dst, associated.angleDeg, nullptr, SDL_FLIP_NONE) != 0){
        std::cout << "ERROR: RenderCopy" << std::endl;
    }
}

int Sprite::GetHeight(){
    return scale.y*height;
}

int Sprite::GetWidth(){
    return scale.x*width;
}

bool Sprite::IsOpen(){
    return (texture == nullptr ? false : true);
}

void Sprite::Update(float dt){}

bool Sprite::Is(std::string type){
    return (type == "Sprite" ? true : false);
}

void Sprite::SetScale(float scaleX, float scaleY){
    scaleX == 0 ? scale.x = scale.x : scale.x = scaleX;
    scaleY == 0 ? scale.y = scale.y : scale.y = scaleY;
}

Vec2 Sprite::GetScale(){
    return scale;
}