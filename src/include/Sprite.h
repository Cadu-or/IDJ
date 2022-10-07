#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include "GameObject.h"
#include "Resources.h"
#include "Timer.h"

#include <bits/stdc++.h>

class Sprite : public Component{
    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;
        Vec2 scale;
        int frameCount;
        int currentFrame;
        float timeElapsed;
        float frameTime;
        Timer selfDestructCount;
        float secondsToSelfDestruct;
        
    public:
        Sprite(GameObject& associated);
        Sprite(GameObject& associated, std::string file, int frameCount = 1, float frameTime = 1, float secondsToSelfDestruct = 0);
        ~Sprite();
        void Open(std::string file);
        void SetClip(int x, int y, int w, int h);
        void Render();
        void Render(float x, float y);
        int GetWidth();
        int GetHeight();
        bool IsOpen();
        void Update(float dt);
        bool Is(std::string type);
        void SetScale(float scalex, float scaley);
        Vec2 GetScale();
        void SetFrame(int frame);
        void SetFrameCount(int frameCount);
        void SetFrameTime(float frameTime);
        void NotifyCollision(GameObject& other);
};

#endif