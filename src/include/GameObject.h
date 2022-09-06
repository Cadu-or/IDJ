#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "Component.h"
#include "Rect.h"

class Component;
class GameObject{
    public:
        GameObject();
        ~GameObject();

        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(std::string type);
        void Start();
        bool started;
        Rect box;

        double angleDeg;
        
    private:
        std::vector<std::unique_ptr<Component>> components;
        bool isDead;
};

#endif