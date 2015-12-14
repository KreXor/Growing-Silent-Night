#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include "SDL2/SDL.h"
#include "State.h"
#include "../Player.h"
#include "../Map/Map.h"
#include "../Physics/Physics.h"
#include "../Physics/Lightning.h"
#include "../InputHandler.h"
#include "../Ui/Menu.h"
#include "../Ui/DialogHandler.h"


class WorldState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static WorldState* Instance() {
		return &m_WorldState;
	}



protected:
	WorldState() { }


private:
	static WorldState m_WorldState;
	GraphicHelper graphicHelper;
	InputHandler inputHandler;

	SDL_Texture* map;
	SDL_Texture* yellow_arrow;
	SDL_Texture* ximg;
	SDL_Rect arrowPos;
	SDL_Rect mapPos;

	int alpha;
};

#endif
