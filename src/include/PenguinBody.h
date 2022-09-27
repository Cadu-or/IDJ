#ifndef PENGUINBODY_H
#define PENGUINBODY_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"
#include "Sprite.h"

class PenguinBody : public Component{
    public:
        PenguinBody(GameObject& associated);
        ~PenguinBody();

        void Update(float dt);
        void Render();
        void Start();
        void NotifyCollision(GameObject &other);
        bool Is(std::string type);

        Vec2 GetCenter();

        static PenguinBody* player;

    private:
        std::weak_ptr <GameObject> pcannon;
        Vec2 speed;
        float linearSpeed;
        float angle;
        int hp;
};

#endif