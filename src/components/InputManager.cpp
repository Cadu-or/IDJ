#include "../include/InputManager.h"

InputManager& InputManager::GetInstance(){
    static InputManager instance;
    return instance;
}

InputManager::InputManager(){
    for(int i = 0; i < 6; i++){
        mouseState.push_back(false);
    }

    for(int i = 0; i < 6; i++){
        mouseUpdate.push_back(0);
    }

    updateCounter = 0;
    mouseX = 0;
    mouseY = 0;

    quitRequested = false;
}

void InputManager::Update(){
    SDL_Event event;
    SDL_GetMouseState(&mouseX, &mouseY);
    // std::cout << "x:" << GetMouseX() << std::endl;
    // std::cout << "y:" << GetMouseY() << std::endl;
    quitRequested = false;
    updateCounter++;

    while(SDL_PollEvent(&event)){
        switch(event.type){

        case SDL_QUIT:
            // std::cout << "ESC" << std::endl;
            quitRequested = true;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if(!event.key.repeat){
                // std::cout << "MOUSE DOWN" << std::endl;
                mouseState[event.button.button] = true;
                mouseUpdate[event.button.button] = updateCounter;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            // std::cout << "MOUSE UP" << std::endl;
            mouseState[event.button.button] = false;
            mouseUpdate[event.button.button] = updateCounter;
            break;
        
        case SDL_KEYDOWN:
            if(!event.key.repeat){
                // std::cout << "KEY DOWN" << std::endl;
                keyState[event.key.keysym.sym] = true;
                keyUpdate[event.key.keysym.sym] = updateCounter;
            }
            break;
        
        case SDL_KEYUP:
            // std::cout << "KEY UP" << std::endl;
            keyState[event.key.keysym.sym] = false;
            keyUpdate[event.key.keysym.sym] = updateCounter;
            break;

        default:
            break;
        }
    }
}

bool InputManager::KeyPress(int key){
    auto it = keyUpdate.find(key);

    if(it != keyUpdate.end()){
        if(it->second == updateCounter){
            return keyState.find(key)->second;
        }
    }

    return false;
}

bool InputManager::KeyRelease(int key){
    auto it = keyUpdate.find(key);

    if(it != keyUpdate.end()){
        if(it->second == updateCounter){
            return !keyState.find(key)->second;
        }
    }

    return false;
}

bool InputManager::MousePress(int button){
    if(mouseUpdate[button] == updateCounter){
        return mouseState[button];
    }

    return false;
}

bool InputManager::IsKeyDown(int key){
    auto it = keyState.find(key);

    if(it != keyState.end()){
        return it->second;
    }

    return false;
}

bool InputManager::MouseRelease(int button){
    if(mouseState[button] == updateCounter){
        return !mouseState[button];
    }
    return false;
}

bool InputManager::IsMouseDown(int button){
    return mouseState[button];
}

int InputManager::GetMouseX(){
    return mouseX;
}

int InputManager::GetMouseY(){
    return mouseY;
}

bool InputManager::QuitRequested(){
    return quitRequested;
}