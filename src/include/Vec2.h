#ifndef VEC2_H
#define VEC2_H

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <bits/stdc++.h>

class Vec2{
    public:
        float x;
        float y;

        Vec2();
        Vec2(float x, float y);
        Vec2 operator+(Vec2 vet);
        Vec2 operator-(Vec2 vet);
        Vec2 operator*(float escalar);

        float Magnitude();
        Vec2 Normal();
        float Distance(Vec2 &vet);
        float InclX();
        float InclXPoints(Vec2 &vet);
        Vec2 GetRotated(float ang);
};

#endif