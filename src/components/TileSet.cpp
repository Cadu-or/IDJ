#include "../include/TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file){
    SetTileWidth(tileWidth);
    SetTileHeight(tileHeight);

    GameObject *obj = new GameObject();
    this->tileSet = new Sprite(*obj, file);
    
    if(this->tileSet->IsOpen()){
        this -> rows = this -> tileSet->GetHeight() / tileHeight;
        this -> columns = this -> tileSet->GetWidth() / tileWidth;
    }

}

void TileSet::RenderTile(unsigned int index, float x, float y){
    if(index >= 0 and index <= rows * columns){
        int auxx = (index%columns) * tileWidth;
        int auxy = (index/columns) * tileHeight;
        tileSet -> SetClip(auxx, auxy, tileWidth, tileHeight);
        tileSet -> Render(x,y);
    }
}

int TileSet::GetTileWidth(){
    return tileWidth;
}

int TileSet::GetTileHeight(){
    return tileHeight;
}

void TileSet::SetTileWidth(int tileWidth){
    this->tileWidth = tileWidth;
}

void TileSet::SetTileHeight(int tileHeight){
    this->tileHeight = tileHeight;
}