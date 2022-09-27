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
#include "Timer.h"

class Alien : public Component{
    private:
        Vec2 speed;
        int hp;
        std::vector<std::weak_ptr<GameObject>> minionArray;
        int nMinions;

        enum AlienState {MOVING, RESTING};
        AlienState state;
        Timer restTimer;
        Vec2 destination;

    public:
        Alien(GameObject& associated, int nMinions);
        void Start();

        void Update(float dt);
        void Render();
        bool Is(std::string type);
        void NotifyCollision(GameObject &other);

        static int alienCount;

        ~Alien();
};

#endif