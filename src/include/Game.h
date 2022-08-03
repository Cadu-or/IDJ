#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "State.h"

class Game{
    private:
        std::string title;
        int width;
        int height;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;

        static Game* Instance;

    public:
        Game(std::string title, int width, int height);
        void Run();

        SDL_Renderer* GetRenderer();
        State& GetState();

        static Game& GetInstance();
        ~Game();
};

#endif