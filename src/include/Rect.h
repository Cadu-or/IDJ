#ifndef RECT_H
#define RECT_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include "Vec2.h"
#include <bits/stdc++.h>

class Rect{
    public:
        float x;
        float y;
        float w;
        float h;

        Rect();
        Rect(float x, float y, float w, float h);
        Rect operator+(Vec2 vet);
        Rect SumVec2(Vec2 vet, Rect rect);
        Vec2 CoordCenter();
        bool Contains(Vec2 vet);
};

#endif