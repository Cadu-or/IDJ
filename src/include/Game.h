#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF

#include "SDL_include.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
#include "State.h"
#include "InputManager.h"
#include "StageState.h"

class Game{
    private:
        void CalculateDeltaTime();

        int frameStart;
        float dt;
        
        static Game* Instance;
        
        State* storedState;
        SDL_Window* window;
        SDL_Renderer* renderer;
        std::stack<std::unique_ptr<State>> stateStack;

    public:
        Game(std::string title, int width, int height);
        ~Game();

        static Game& GetInstance();
        SDL_Renderer* GetRenderer();
        State& GetCurrentState();
        
        void Push(State* state);

        void Run();

        float GetDeltaTime();
};

#endif