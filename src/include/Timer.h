#ifndef TIMER_H
#define TIMER_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"

class Timer{
    public:
        Timer();
        void Update(float dt);
        void Restart();
        float Get();

    private:
        float time;
};

#endif