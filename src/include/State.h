#ifndef STATE_H
#define STATE_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
#include "Face.h"
#include "Component.h"
#include "Sound.h"
#include "TileMap.h"
#include "TileSet.h"
#include "InputManager.h"
#include "CameraFollower.h"

class State{
    private:
        Sprite* bg;
        Music* music;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectarray;
        void AddObject(int mouseX, int mouseY);

    public:
        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        ~State();

};

#endif