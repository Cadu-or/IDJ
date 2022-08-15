#ifndef MUSIC_H
#define MUSIC_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "Resources.h"

class Music{
    private:
        Mix_Music* music;

    public:
        Music();
        Music(std::string file);

        void Play(int times = -1);
        void Stop(int msToStop = 1500);
        void Open(std::string file);
        bool IsOpen();

        ~Music();
};

#endif