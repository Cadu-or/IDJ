#include "../include/TileMap.h"

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet):Component(associated){
    this->tileSet = tileSet;
    Load(file);
}

void TileMap::Load(std::string file){
    std::fstream fs;
    fs.open(file, std::fstream::in);
    std::string c;
    std::vector<int>nums;

    getline(fs, c);

    for(int i = 0; i < c.size(); i+=3){
        std::string num;
        num.push_back(c[i]);
        num.push_back(c[i+1]);
        int aux = std::stoi(num);
        nums.push_back(aux);
    }

    getline(fs, c);

    mapWidth = nums[0];
    mapHeight = nums[1];
    mapDepth = nums[2];

    for(int j = 0; j < 25; j++){
        getline(fs, c);
        for(int i = 0; i < c.size()-1; i+=3){
            std::string num;
            num.push_back(c[i]);
            num.push_back(c[i+1]);
            int aux = stoi(num) - 1;
            tileMatrix.push_back(aux);
        }
    }

    getline(fs, c);

    for(int j = 0; j < 25; j++){
        getline(fs, c);
        for(int i = 0; i < c.size()-1; i+=3){
            std::string num;
            num.push_back(c[i]);
            num.push_back(c[i+1]);
            int aux = stoi(num) - 1;
            tileMatrix.push_back(aux);
        }
    }

    fs.close();
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y,  int z){
    return (int&) tileMatrix[z*mapHeight*mapWidth + y*mapWidth + x];
}

void TileMap::Render(){
    for(int i = 0; i < mapDepth; i++){
        RenderLayer(i, Camera::pos.x, Camera::pos.y);
    }
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    for(int i = 0; i < mapHeight; i++){
        for(int j = 0; j < mapWidth; j++){
            int x = j * tileSet->GetTileWidth() - cameraX*((layer+1));
            int y = i * tileSet->GetTileHeight() - cameraY*((layer+1));
            tileSet->RenderTile(At(j,i,layer),x,y);
        }
    }
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}

void TileMap::Update(float dt){}

bool TileMap::Is(std::string type){
    return (type == "TileMap" ? true : false);
}