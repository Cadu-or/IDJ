#ifndef ALIEN_H
#define ALIEN_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "Component.h"
#include "Sound.h"
#include "InputManager.h"
#include "Camera.h"
#include "Sprite.h"
#include "Minion.h"
#include "State.h"
#include <time.h>

class Alien : public Component{
    private:
        class Action{
            public:
                enum ActionType{MOVE, SHOOT};
                Action(ActionType type, float x, float y);
                ActionType type;
                Vec2 pos;
        };

        Vec2 speed;
        int hp;
        std::queue<Action> taskQueue;
        std::vector<std::weak_ptr<GameObject>> minionArray;
        int nMinions;

    public:
        Alien(GameObject& associated, int nMinions);

        void Start();

        void Update(float dt);
        void Render();
        bool Is(std::string type);

        ~Alien();
};

#endif