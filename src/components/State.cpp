#include "../include/State.h"
#include <math.h>

State::State(){
    // std::cout << "STATE" << std::endl;
    GameObject* obj = new GameObject();
    bg = new Sprite(*obj, "./src/resources/img/ocean.jpg");
	
    obj->AddComponent(bg);
    obj->box.x = 0;
    obj->box.y = 0;
    objectarray.emplace_back(obj);

	GameObject* obj2 = new GameObject();
	TileSet* tileset = new TileSet(64,64, "./src/resources/img/tileset.png");
	TileMap* tilemap = new TileMap(*obj2, "./src/resources/map/tileMap.txt", tileset);
	obj->AddComponent(tilemap);
	obj->box.x = 0;
	obj->box.y = 0;
	objectarray.emplace_back(obj2);


    music = new Music("./src/resources/audio/stageState.ogg");
    music->Play();
    quitRequested = false;
}

void State::Update(float dt){
    Input();
    for(int i = 0; i < objectarray.size(); i++){
        objectarray[i]->Update(dt);
    }

    for(int i = 0; i < objectarray.size(); i++){
        if(objectarray[i]->IsDead()){
            objectarray.erase(objectarray.begin() + i);            
        }
    }
}

void State::Render(){
    for(int i = 0; i < objectarray.size(); i++){
        objectarray[i]->Render();
    }
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectarray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectarray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.Contains(Vec2((float)mouseX, (float)mouseY))) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::AddObject(int mouseX, int mouseY){
    GameObject* obj = new GameObject();
    Sprite* sp = new Sprite(*obj, "./src/resources/img/penguinface.png");

    obj->AddComponent(sp);
    obj->box.x = mouseX - obj->box.CoordCenter().x;
    obj->box.y = mouseY - obj->box.CoordCenter().y;

    Sound* snd = new Sound(*obj, "./src/resources/audio/boom.wav");
    obj->AddComponent(snd);

    Face* fc = new Face(*obj);
    obj->AddComponent(fc);

    objectarray.emplace_back(obj);

}

State::~State(){
    objectarray.clear();
}

void State::LoadAssets(){}