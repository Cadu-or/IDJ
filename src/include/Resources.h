#ifndef RESOURCES_H
#define RESOURCES_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include <bits/stdc++.h>
#include <unordered_map>
#include "SDL_include.h"

class Resources{
    private:
        static std::unordered_map<std::string, SDL_Texture*> imageTable;
        static std::unordered_map<std::string, Mix_Music*> musicTable;
        static std::unordered_map<std::string, Mix_Chunk*> soundTable;

    public:
        static SDL_Texture* GetImage(std::string file);
        static Mix_Music* GetMusic(std::string file);
        static Mix_Chunk* GetSound(std::string file);

        static void ClearImages();
        static void ClearMusics();
        static void ClearSounds();
};       

#endif