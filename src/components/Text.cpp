#include "../include/Text.h"
#include "../include/Game.h"

Text::Text(GameObject& associated, std::string fontFile, int fontSize, TextStyle style, std::string text, SDL_Color color) : Component(associated){
    this->fontFile = fontFile;
    this->fontSize = fontSize;
    this->style = style;
    this->text = text;
    this->texture = nullptr;
    this->color = color;
    font = Resources::GetFont(fontFile, fontSize);
    RemakeTexture();
}

Text::~Text(){
    SDL_DestroyTexture(texture);
}

void Text::Update(float dt){
}

void Text::Render(){
    SDL_Rect rec;

    rec.x = associated.box.x - Camera::pos.x;
    rec.y = associated.box.y - Camera::pos.y;
    rec.w = associated.box.w;
    rec.h = associated.box.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, nullptr, &rec);
}

void Text::SetText(std::string text){
    this->text = text;
    RemakeTexture();
}

void Text::SetColor(SDL_Color color){
    this->color = color;
    RemakeTexture();
}

void Text::SetStyle(TextStyle style){
    this->style = style;
    RemakeTexture();
}

void Text::SetFontFile(std::string fontFile){
    this->fontFile = fontFile;
    RemakeTexture();
}

void Text::SetFontSize(int fontsize){
    this->fontSize = fontSize;
    RemakeTexture();
}

void Text::RemakeTexture(){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    SDL_Surface* surface = nullptr;

    switch(style){
        case SOLID:
            surface = TTF_RenderText_Solid(font, text.c_str(), color);
            break;

        case SHADED:
            surface = TTF_RenderText_Shaded(font, text.c_str(), color, SDL_Color{0,0,0,0});
            break;

        case BLENDED:
            surface = TTF_RenderText_Blended(font, text.c_str(), color);
            break;
        
        default:
            surface = TTF_RenderText_Solid(font, text.c_str(), color);
            break;
    }

    texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), surface);

    if(texture == nullptr){
        std::cout << "FONT ERROR" << std::endl;
    }

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    // std::cout << "QueryT" << std::endl;
    associated.box.w = w;
    associated.box.h = h;
}

bool Text::Is(std::string type){
    return (type == "Text" ? true : false);
}