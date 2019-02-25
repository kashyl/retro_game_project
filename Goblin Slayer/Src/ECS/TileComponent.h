#pragma once
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL.h"

class TileComponent : public Component
{
public:
	/*TransformComponent *transform;
	SpriteComponent *sprite

	SDL_Rect tileRect;
	int tileID;

	const char* path;*/

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	TileComponent() = default;

	~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}

	TileComponent(int srcX, int srcY, int xpos, int ypos, const char* path)
	{
		texture = TextureManager::LoadTexture(path);

		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = 32;

		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = destRect.h = 32;
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
	
		/*{
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;*/






		/*switch (tileID)
		{
		case 0:
			path = "assets/dirt1.png";
			break;
		case 1:
			path = "assets/grass1.png";
			break;
		case 2:
			path = "assets/grass2.png";
			break;
		case 3:
			path = "assets/water1.png";
			//break;
		default:
			break;
		}
	}

	void init() override
	{
		entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);
		sprite = &entity->getComponent<SpriteComponent>();
	}*/
};