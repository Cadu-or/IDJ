#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
#include "State.h"
#include "InputManager.h"

class Game{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;
        static Game* Instance;
        Game(std::string title, int width, int height);
        int frameStart;
        float dt;
        void CalculateDeltaTime();

    public:
        void Run();

        SDL_Renderer* GetRenderer();
        State& GetState();

        static Game& GetInstance();
        ~Game();

        float GetDeltaTime();
};

#endif