#ifndef ENDSTATE_H
#define ENDSTATE_H

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
#include "GameData.h"
#include "TitleState.h"

class EndState : public State{
    private:
        Music* backgroundMusic;
    
    public:
        EndState();
        ~EndState();

        void LoadAssets();
        void Update(float dt);
        void Render();
        
        void Start();
        void Pause();
        void Resume();

};

#endif