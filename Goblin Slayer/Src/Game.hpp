#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }

	
	static SDL_Renderer *renderer;
	static SDL_Event event;
	//static std::vector<ColliderComponent*> colliders;

	static bool isRunning;

	static SDL_Rect camera;

	//32 groups max  
	enum groupLabels : std::size_t
	{
		groupMap,
		groupPlayers,
		groupEnemies,
		groupColliders,
		groupUI //*
	};
 
private:
	int cnt = 0;

	SDL_Window *window;
	
};

#endif /* Game_hpp */