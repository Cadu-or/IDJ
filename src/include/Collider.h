#ifndef COLLIDER_H
#define COLLIDER_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"
#include "Sprite.h"


class Collider : public Component{
    public:
        Collider(GameObject& associated, Vec2 scale = {1,1}, Vec2 offset = {0,0});
        Rect box;

        void Render();
        bool Is(std::string type);
        void Update(float dt);
        void Start();

        void SetScale(Vec2 scale);
        void SetOffset(Vec2 offset);

        bool IsColliding(Collider cllrect);

    private:
        Vec2 scale;
        Vec2 offset;

};

#endif