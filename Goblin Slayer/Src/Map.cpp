#include "Map.h"
#include "Game.hpp"
#include <fstream>
#include "ECS/ECS.h"
#include "ECS/Components.h"

extern Manager manager;

Map::Map(const char* mfp, int ms, int ts) : mapFilePath(mfp), mapScale(ms), tileSize(ts)
{
	scaledSize = ms * ts;
}

//help with memory issues
Map::~Map()
{

}


void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
	char c;
	std::fstream mapFile;
	mapFile.open(path);

	int srcX, srcY;


	for (int y = 0; y < sizeY; y++) { 
		for (int x = 0; x < sizeX; x++) {

			mapFile.get(c);
			srcY = atoi(&c) * tileSize;
			mapFile.get(c);
			srcX = atoi(&c) * tileSize;
			AddTile(srcX, srcY, x * (tileSize * mapScale), y * (tileSize * mapScale));
			mapFile.ignore();
		}
	}

	mapFile.ignore();

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(c);
			if (c == '1')
			{
				auto& tcol(manager.addEntity());
				tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
				//mapFile.ignore();
				tcol.addGroup(Game::groupColliders);
			}
			mapFile.ignore();
		}
	}

	mapFile.close();
}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, mapFilePath);
	tile.addGroup(Game::groupMap);
}











//#include "TextureManager.h"

/*int lvl1[20][25] = {
	{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0},
	{0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
	{0,0,0,2,2,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0},
	{0,0,0,0,0,2,2,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,2,2,2,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0},
	{0,0,0,0,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0},
	{0,0,0,0,0,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,0,0,0,0},
	{0,0,0,0,0,0,0,2,2,1,1,1,1,1,1,1,1,1,1,2,2,0,0,0,0},
	{0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,2,2,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,2,2,1,1,1,1,1,1,2,2,2,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,2,2,2,2,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,2,2,2,2,0,1,1}
};

Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/dirt1.png");
	grass = TextureManager::LoadTexture("assets/grass1.png");
	water = TextureManager::LoadTexture("assets/water1.png");

	LoadMap(lvl1);

	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 32;
}

//help with memory issues
Map::~Map()
{
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(water);
	SDL_DestroyTexture(dirt);
}


void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {

			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {

			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type) {
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			default:
				break;
			}

		}
	}
}*/

