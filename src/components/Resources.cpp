#include "../include/Resources.h"
#include "../include/Game.h"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(std::string file){
    auto it = Resources::imageTable.find(file);
    if(it != Resources::imageTable.end()){
        return it->second;
    }else{
        Resources::imageTable[file] = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    }
    return imageTable[file];
}

void Resources::ClearImages(){
    for(auto i = Resources::imageTable.begin(); i != Resources::imageTable.end();i++){
        SDL_DestroyTexture(i->second);
    }
}

Mix_Music* Resources::GetMusic(std::string file){
    auto it = Resources::musicTable.find(file);
    if(it != Resources::musicTable.end()){
        return it->second;
    }else{
        Resources::musicTable[file] = Mix_LoadMUS(file.c_str());
    }
    return musicTable[file];
}

void Resources::ClearMusics(){
    for(auto i = Resources::musicTable.begin(); i != Resources::musicTable.end();i++){
        Mix_FreeMusic(i->second);
    }
}

Mix_Chunk* Resources::GetSound(std::string file){
    auto it = Resources::soundTable.find(file);
    if(it != Resources::soundTable.end()){
        return it->second;
    }else{
        Resources::soundTable[file] = Mix_LoadWAV(file.c_str());
    }
    return soundTable[file];
}

void Resources::ClearSounds(){
    for(auto i = Resources::soundTable.begin(); i != Resources::soundTable.end(); i++){
        Mix_FreeChunk(i->second);
    }
}

