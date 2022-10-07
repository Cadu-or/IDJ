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
    public:
        State();
        virtual ~State();

        virtual void LoadAssets() = 0;
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;

        virtual void Start() = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual std::weak_ptr <GameObject> AddObject(GameObject* go);
        virtual std::weak_ptr <GameObject> GetObjectPtr(GameObject* go);
        
        bool QuitRequested();
        bool PopRequested();
    
    protected:
        void StartArray();
        virtual void UpdateArray(float dt);
        virtual void RenderArray();
        
        bool popRequested;
        bool quitRequested;
        bool started;

        std::vector<std::shared_ptr<GameObject>> objectarray;
};

#endif