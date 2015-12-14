#ifndef MINIGAMEPETSTATE_H
#define MINIGAMEPETSTATE_H

#include "SDL2/SDL.h"
#include "../State.h"
#include "../../Player.h"
#include "../../Map/Map.h"
#include "../../Physics/Physics.h"
#include "../../Physics/Lightning.h"
#include "../../InputHandler.h"
#include "../../Ui/DialogHandler.h"
class MiniGamePetState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static MiniGamePetState* Instance() {
		return &m_MiniGamePetState;
	}

protected:
	MiniGamePetState() { }

private:
	bool checkIfCollide(GameEngine* game, int side);
	int life;
	
	static MiniGamePetState m_MiniGamePetState;
	Player player;
	Map worldmap;
	Lightning lightning;
	Physics physics;
	InputHandler inputHandler;
	DialogHandler dialogHandler;
	DialogHandler dialogHandler2;

	GraphicHelper graphicHelper;
	SDL_Texture* bar_blue;
	SDL_Texture* bar_bot;
	SDL_Texture* bar_delimeter;
	SDL_Texture* bar_green;
	SDL_Texture* bar_red;
	SDL_Texture* bar_top;
	SDL_Texture* yellow_arrow;
	SDL_Texture* bar_top_empty;

	SDL_Rect arrowPosition;
	float arrowSpeed;
	int delimeterHeigth;
	int blueHeigth;
	int greenHeigth;
	int redHeigth;
	int arrowDirection;

	int powerBlueHeigth;
	int powerEmptyHeigth;
	int powerIncrease;

	int arrowTaken;


	int alpha;
};

#endif
