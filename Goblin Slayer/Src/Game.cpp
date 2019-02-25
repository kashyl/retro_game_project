#include "Game.hpp"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& enemy(manager.addEntity());
auto& wall(manager.addEntity());

const char* mapfile = "assets/map2_32x32_tileset.png";

//32 groups max  
enum groupLabels : std::size_t
{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created." << std::endl;
		}

		isRunning = true;
	} else {
		isRunning = false;
	}

	map = new Map();

	//implement ecs here
	//TransformComponent(float x, float y, int h, int w, int sc)
	//SpriteComponent(const char* path, bool isAnimated)

	Map::LoadMap("assets/map2_32x32.txt", 32, 32);

	player.addComponent<TransformComponent>(400.0f, 320.0f, 32, 32, 2);
	player.addComponent<SpriteComponent>("assets/adv1_anim.png", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("Player ");
	player.addGroup(groupPlayers);

	/*enemy.addComponent<TransformComponent>(300.0f, 200.0f, 80, 64, 1);
	enemy.addComponent<SpriteComponent>("assets/knight1_idle.png", true);
	enemy.addComponent<ColliderComponent>("Forgotten Knight");
	enemy.addGroup(groupEnemies);*/

	enemy.addComponent<TransformComponent>(350.0f, 400.0f, 80, 64, 1);
	enemy.addComponent<SpriteComponent>("assets/knight1_idle.png", true);
	enemy.addComponent<ColliderComponent>("Enemy1");
	enemy.addGroup(groupEnemies);

	wall.addComponent<TransformComponent>(300.0f, 170.0f, 200, 20, 1);
	wall.addComponent<SpriteComponent>("assets/wall1.png");
	wall.addComponent<ColliderComponent>("Wall (Cobblestone)");
	wall.addGroup(groupMap);
}

void Game::handleEvents()
{
	
	SDL_PollEvent(&event);
	switch (event.type) {
	    case SDL_QUIT:
		    isRunning = false;
		    break;
		default:
			break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();

	Vector2D pVel = player.getComponent<TransformComponent>().velocity;
	int pSpeed = player.getComponent<TransformComponent>().speed;

	/*for (auto t : tiles)
	{
		t->getComponent<TileComponent>().destRect.x += -(pVel.x * pSpeed);
		t->getComponent<TileComponent>().destRect.y += -(pVel.y * pSpeed);
	}*/

	for (auto cc : colliders)
	{
		//Collision::AABB(player.getComponent<ColliderComponent>(), *cc);

		if (Collision::AABB(player.getComponent<ColliderComponent>(), wall.getComponent<ColliderComponent>()))
		{
			player.getComponent<TransformComponent>().velocity * -1;
		}
			//player.getComponent<TransformComponent>().scale = 1;
			//player.getComponent<TransformComponent>().velocity * -1;
			//std::cout << "Wall Hit!" << std::endl;
	}
}


void Game::render()
{
	SDL_RenderClear(renderer);
	//manager.draw();

	//this will render each tile, players, enemies etc.
	for (auto& t : tiles)
	{
		t->draw();
	}

	for (auto& p : players)
	{
		p->draw();
	}
	for (auto& e : enemies)
	{
		e->draw();
	}
	
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned." << std::endl;
}

void Game::AddTile(int srcX, int srcY, int xpos, int ypos)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, mapfile);
	tile.addGroup(groupMap);
}
