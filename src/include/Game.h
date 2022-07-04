#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include "State.h"

class Game{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;
        static Game* Instance;
        Game(std::string title, int width, int height);

    public:
        void Run();

        SDL_Renderer* GetRenderer();
        State& GetState();

        static Game& GetInstance();
        ~Game();
};

#endif