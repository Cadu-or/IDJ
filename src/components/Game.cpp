#include "../include/Game.h"

Game* Game::Instance(nullptr);

Game& Game::GetInstance(){
    if(Instance == nullptr){
        Instance = new Game("Carlos Eduardo de O Ribeiro - 180099094", 1024, 600);
    }
    srand(time(NULL));
    return *Instance;
}

Game::Game(std::string title, int width, int height){
    if(Instance != nullptr){
        std::cout << "ERROR" << std::endl;
    }else{
        Instance = this;
    }

    try{
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0 ? throw std::string("SDL") : NULL;
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0 ? throw std::string("IMG") : NULL;
        Mix_Init(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MP3 | MIX_INIT_MOD) == 0? throw std::string("AUDIO") : NULL;
        Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0 ? throw std::string("O_AUDIO") : NULL;
        
    }catch (std::string error){
        std::cout << "Erro: " << error << std::endl;
    }

    Mix_AllocateChannels(32);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == nullptr){
        std::cout << "ERROR WINDOW" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if(renderer == nullptr){
        std::cout << "ERROR RENDERED" << std::endl;
    }

    frameStart = 0;
    dt = 0;
    state = new State();
    // std::cout << "STATE" << std::endl;
}

Game::~Game(){
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Instance = nullptr;
    delete Instance;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

State& Game::GetState(){
    return *state;
}

void Game::Run(){
    while(state->QuitRequested() != true){
        CalculateDeltaTime();
        // std::cout << "DeltaTime: " << dt << std::endl;
        InputManager::GetInstance().Update();
        state->Update(dt);
        // std::cout << "=== Update ===" << std::endl;
        state->Render();
        // std::cout << "=== Render ===" << std::endl;
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    Resources::ClearImages();
    Resources::ClearSounds();
    Resources::ClearMusics();
}

void Game::CalculateDeltaTime(){
    int frame = frameStart;
    frameStart = SDL_GetTicks();
    // std::cout << "now:" << frameStart << std::endl;
    // std::cout << "ant:" << frame << std::endl;
    dt = (float)(frameStart - frame)/1000;
}

float Game::GetDeltaTime(){
    return dt;
}
