#ifndef TITLESTATE_H
#define TITLESTATE_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "State.h"
#include "GameObject.h"
#include "Text.h"

class TitleState : public State{
    public:
        TitleState();
        ~TitleState();

        void LoadAssets();
        void Update(float dt);
        void Render();

        void Start();
        void Pause();
        void Resume();
};

#endif