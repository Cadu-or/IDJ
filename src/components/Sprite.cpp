#include "../include/Sprite.h"
#include "../include/Game.h"

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(std::string file){
    // std::cout << "Sprite file: " << file << std::endl;
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file){

    texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file.c_str());
    std::cout << texture << std::endl;
    if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) != 0){
        std::cout << "ERROR: QueryTexture" << std::endl;
    }
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y){
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = clipRect.w;
    dst.h = clipRect.h;

    if(SDL_RenderCopy(Game::GetInstance()->GetRenderer(), texture, &clipRect, &dst) != 0){
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
    if(texture == nullptr){
        return false;

    }else{
        return true;

    }
}