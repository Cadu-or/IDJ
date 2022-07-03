#include "../include/Music.h"

Music::Music(){
    music = nullptr;
}

Music::Music(std::string file){
    // std::cout << "Music file: " << file << std::endl;
    music = nullptr;
    Open(file);
}

void Music::Play(int times){
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    music = Mix_LoadMUS(file.c_str());

    if(!IsOpen()){
        std::cout << "ERROR: NULLPTR in Music" << std::endl;
    }
}

bool Music::IsOpen(){
    return (music == nullptr ? false : true);
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}