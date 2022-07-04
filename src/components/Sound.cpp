#include "../include/Sound.h"

Sound::Sound(GameObject& associated):Component(associated){
    this->chunk = nullptr;
}

Sound::Sound(GameObject& associated, std::string file):Sound(associated){
    Open(file);
}

void Sound::Play(int times){
    SetChannel(Mix_PlayChannel(-1, this->chunk, times-1));
}

void Sound::Stop(){
    if(this->chunk != nullptr){
        Mix_HaltChannel(GetChannel());
    }
}

void Sound::Open(std::string file){
    this->chunk = Mix_LoadWAV(file.c_str());
    if(this->chunk == nullptr){
      std::cout << "ERROR: LoadWAV" << std::endl;  
    }
}

void Sound::SetChannel(int channel){
    this->channel = channel;
}

int Sound::GetChannel(){
    return this->channel;
}

Sound::~Sound(){
    Stop();
    if(this->chunk != nullptr){
        Mix_FreeChunk(this->chunk);
    }
}

bool Sound::Is(std::string type){
    return (type == "Sound" ? true : false);
}

void Sound::Render(){}

void Sound::Update(float dt){}

