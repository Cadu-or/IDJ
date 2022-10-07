#include "../include/Collider.h"
#include "../include/Camera.h"
#include "../include/Game.h"

Collider::Collider(GameObject& associated, Vec2 scale, Vec2 offset) : Component(associated){
    this->scale = scale;
    this->offset = offset;
}

void Collider::Update(float dt){
    box = associated.box;
    box.w = box.w*scale.x;
    box.h = box.h*scale.y;

    offset.GetRotated(associated.angleDeg);
    box.x = box.CoordCenter().x - box.w/2 + offset.x;
    box.y = box.CoordCenter().y - box.h/2 + offset.y;
}

void Collider::Render(){
    // Vec2 center( box.CoordCenter() );
	// SDL_Point points[5];

	// Vec2 point = (Vec2(box.x, box.y) - center).GetRotated( associated.angleDeg/(180/M_PI) )
	// 				+ center - Camera::pos;
	// points[0] = {(int)point.x, (int)point.y};
	// points[4] = {(int)point.x, (int)point.y};
	
	// point = (Vec2(box.x + box.w, box.y) - center).GetRotated( associated.angleDeg/(180/M_PI) )
	// 				+ center - Camera::pos;
	// points[1] = {(int)point.x, (int)point.y};
	
	// point = (Vec2(box.x + box.w, box.y + box.h) - center).GetRotated( associated.angleDeg/(180/M_PI) )
	// 				+ center - Camera::pos;
	// points[2] = {(int)point.x, (int)point.y};
	
	// point = (Vec2(box.x, box.y + box.h) - center).GetRotated( associated.angleDeg/(180/M_PI) )
	// 				+ center - Camera::pos;
	// points[3] = {(int)point.x, (int)point.y};

	// SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
	// SDL_RenderDrawLines(Game::GetInstance().GetRenderer(), points, 5);
}

bool Collider::Is(std::string type){
    return (type == "Collider" ? true : false);
}

void Collider::SetScale(Vec2 scale){
    this->scale = scale;
}

void Collider::SetOffset(Vec2 offset){
    this->offset = offset;
}

void Collider::Start(){}