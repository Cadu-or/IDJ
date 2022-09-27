#ifndef PENGUINCANNON_H
#define PENGUINCANNON_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"
#include "Sprite.h"
#include "Timer.h"

class PenguinCannon : public Component{
    public:
        PenguinCannon(GameObject& associated, std::weak_ptr <GameObject> penguinBody);

        void Update(float dt);
        void Render();
        void Start();
        bool Is(std::string type);
        void NotifyCollision(GameObject &other);

        void Shoot();
        Timer timer;

    private:
        std::weak_ptr <GameObject> pbody;
        float angle;
};

#endif