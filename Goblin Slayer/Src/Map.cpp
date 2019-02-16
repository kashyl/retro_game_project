#include "Map.h"
#include "Game.hpp"
#include <fstream>

Map::Map()
{

}

//help with memory issues
Map::~Map()
{

}


void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++) { 
		for (int x = 0; x < sizeX; x++) {

			mapFile.get(tile);
			Game::AddTile(atoi(&tile), x * 32, y * 32);
			mapFile.ignore();
		}
	}

	mapFile.close();
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

