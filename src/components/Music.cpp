#include "../include/Music.h"

Music::Music(){}

Music::Music(std::string file){
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
    // std::cout << "MUSIC: "<< music << std::endl;
    if(!IsOpen()){
        std::cout << "ERROR: NULLPTR in Music" << std::endl;
    }
}

bool Music::IsOpen(){
    return (music == nullptr ? false : true);
}

Music::~Music(){
    Stop(1500);
    Mix_FreeMusic(music);
}