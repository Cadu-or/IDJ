#ifndef MINION_H
#define MINION_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "Component.h"
#include "Sound.h"
#include "InputManager.h"
#include "Camera.h"
#include "Sprite.h"
#include "Bullet.h"
#include <time.h>

class Minion : public Component{
    private:
        std::weak_ptr<GameObject> alienCenter;
        float arc;

    public:
        Minion(GameObject& associated,std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);

        void Update(float dt);
        void Render();
        bool Is(std::string type);
        void NotifyCollision(GameObject &other);

        void Shoot(Vec2 target);

        ~Minion();
};

#endif