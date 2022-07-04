#include "../include/Sprite.h"
#include "../include/Game.h"

Sprite::Sprite(GameObject& associated):Component(associated){
    texture = nullptr;
}

Sprite::Sprite(GameObject& associated, std::string file):Component(associated){
    // std::cout << "Sprite file: " << file << std::endl;
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file){
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
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
    SDL_Rect dst;
    dst.x = associated.box.x;
    dst.y = associated.box.y;
    dst.w = associated.box.w;
    dst.h = associated.box.h;

    if(SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dst) != 0){
        std::cout << "ERROR: RenderCopy" << std::endl;
    }
}

int Sprite::GetHeight(){
    return height;
}

int Sprite::GetWidth(){
    return width;
}

bool Sprite::IsOpen(){
    return (texture == nullptr ? false : true);
}

void Sprite::Update(float dt){}

bool Sprite::Is(std::string type){
    return (type == "Sprite" ? true : false);
}