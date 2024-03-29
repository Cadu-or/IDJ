#ifndef TILEMAP_H
#define TILEMAP_H

#include <bits/stdc++.h>
#include <fstream>
#include "TileSet.h"
#include "GameObject.h"
#include "Camera.h"

class TileMap : public Component {
    public:
        TileMap(GameObject& associated, std::string file, TileSet* tileSet);
        void Load(std::string file);
        void SetTileSet(TileSet* TileSet);
        int& At(int x, int y, int z = 0); 
        void Render();
        void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
        int GetWidth();
        int GetHeight();
        int GetDepth();
        void Update(float dt);
        bool Is(std::string);
        void NotifyCollision(GameObject& other);
    
    private:
        std::vector<int> tileMatrix;
        TileSet* tileSet;
        int mapWidth;
        int mapHeight;
        int mapDepth;
};


#endif