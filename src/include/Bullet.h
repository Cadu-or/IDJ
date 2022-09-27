#ifndef BULLET_H
#define BULLET_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"
#include "Sprite.h"
#include "InputManager.h"

class Bullet : public Component{
    public:
        Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, std::string sprite, int frameCount);
        void Update(float dt);
        void Render();
        bool Is(std::string type);
        int GetDamage();
        void Start();
        void NotifyCollision(GameObject &other);
        bool targetsPlayer;

    private:
        Vec2 speed;
        float distanceLeft;
        int damage;

};

#endif