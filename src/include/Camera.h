#ifndef CAMERA_H
#define CAMERA_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"
#include "Vec2.h"
#include "InputManager.h"

class Camera{
    public:
        static void Follow(GameObject* newFocus);
        static void Unfollow();
        static void Update(float dt);
        static Vec2 pos;
        static Vec2 speed;

    private:
        static GameObject* focus;
};



#endif