#ifndef COMPONENT_H
#define COMPONENT_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"

class GameObject;

class Component{
    public:
        Component(GameObject& associated);
        ~Component();

        virtual void Update(float dt);
        virtual void Render();
        virtual bool Is(std::string type);

    protected:
        GameObject& associated;
};

#endif