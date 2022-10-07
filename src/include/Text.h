#ifndef TEXT_H
#define TEXT_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF

#include "SDL_include.h"
#include <bits/stdc++.h>
#include "Component.h"
#include "GameObject.h"
#include "Resources.h"
#include "Camera.h"
#include "Timer.h"

class Text : public Component{
    public:
        enum TextStyle {SOLID, SHADED, BLENDED};
        
        Text(GameObject& associated, std::string fontFile, int fontSize, TextStyle style, std::string text, SDL_Color color);
        ~Text();

        void Update(float dt);
        void Render();
        bool Is(std::string type);

        void SetText(std::string text);
        void SetColor(SDL_Color color);
        void SetStyle(TextStyle style);
        void SetFontFile(std::string file);
        void SetFontSize(int fontsize);

    private:
        void RemakeTexture();
        TTF_Font* font; 
        SDL_Texture* texture;
        std::string text;
        TextStyle style;
        std::string fontFile;
        int fontSize;
        SDL_Color color;
};

#endif