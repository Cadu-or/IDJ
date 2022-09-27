#ifndef STATE_H
#define STATE_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
#include "Component.h"
#include "Sound.h"
#include "TileMap.h"
#include "TileSet.h"
#include "InputManager.h"
#include "CameraFollower.h"
#include "Alien.h"
#include "PenguinBody.h"
#include "PenguinCannon.h"

class State{
    private:
        Sprite* bg;
        Music* music;
        bool quitRequested;
        std::vector<std::shared_ptr<GameObject>> objectarray;
        void AddObject(int mouseX, int mouseY);
        bool started;

    public:
        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        void Start();
        std::weak_ptr <GameObject> AddObject(GameObject* go);
        std::weak_ptr <GameObject> GetObjectPtr(GameObject* go);
        ~State();

};

#endif