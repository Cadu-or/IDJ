#ifndef TILESET_H
#define TILESET_H

#include <bits/stdc++.h>
#include "SDL_include.h"
#include "Sprite.h"


class TileSet{
    private:
        Sprite* tileSet;
        int rows;
        int columns;
        
        int tileWidth;
        int tileHeight;
    
    public:
        TileSet(int tileWidth, int tileHeight, std::string file);
        void RenderTile(unsigned int index, float x, float y);
        
        int GetTileWidth();
        int GetTileHeight();

        void SetTileWidth(int tileWidth);
        void SetTileHeight(int tileHeight);
};

#endif