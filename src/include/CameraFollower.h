#ifndef CAMERAFOLLOWER_H
#define CAMERAFOLLOWER_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "Component.h"
#include "Camera.h"

class CameraFollower : public Component{
    public:
        CameraFollower(GameObject& go);
        void Update(float dt);
        void Render();
        bool Is(std::string type);
};

#endif