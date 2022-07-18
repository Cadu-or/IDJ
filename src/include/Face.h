#ifndef FACE_H
#define FACE_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "Component.h"
#include "Sound.h"

class Face : public Component{
    private:
        int hitpoints;

    public:
        Face(GameObject& associated);

        void Damage(int damage);

        void Update(float dt);
        void Render();
        bool Is(std::string type);

        void Sethitpoints(int hitpoints);
        int Gethitpoints();

        ~Face();
};

#endif