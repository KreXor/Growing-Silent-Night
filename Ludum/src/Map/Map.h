#ifndef MAP_H
#define MAP_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../GameEngine.h"
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "rapidjson/document.h"
#include <math.h>
#include <vector>

class Map
{

private:
    struct Position{
		float x;
		float y;
	};

	struct Tile{
		SDL_Rect worldPosition;
		SDL_Rect imagePosition;
		int type;
		int blockid;
		int layer;
		int layer2;
		int layer3;
		int layer4;
		int boundingBoxType; // so we know if there is gound have a slope or note, see physics.c for more info.
	};

	SDL_Texture* tilesImage[10];
	SDL_Texture *Load_image( string filename, GameEngine* game );
	int tile_size;
	int tiles_width_count;
	int tiles_heigth_count;


    void calculateLightPoints();
    void addLightPoint(int x, int y);
    void addLightPointToCorner(Tile tile, int corner);

	void readMapData(GameEngine* game, string map_path);

public:

	void RemoveLayer(GameEngine* game, int x, int y, int layer);
	Tile** mapTilePosition;
	void LoadMap(GameEngine* game, string map_path);
	void Draw(GameEngine* game);
	int getTileSize();
	int getTilesHeightCount();
    int getTilesWidthCount();
    bool isWall(Tile tile);
    vector<Position> lightPoints;
	vector<SDL_Rect> tileList;
	int getTileType(int x, int y, int layer);

};


#endif
