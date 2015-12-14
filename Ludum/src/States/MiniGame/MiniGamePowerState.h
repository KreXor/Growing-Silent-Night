#ifndef MINIGAMEPOWERSTATE_H
#define MINIGAMEPOWERSTATE_H

#include "SDL2/SDL.h"
#include "../State.h"
#include "../../Player.h"
#include "../../Map/Map.h"
#include "../../Physics/Physics.h"
#include "../../Physics/Lightning.h"
#include "../../InputHandler.h"
#include "../../Ui/DialogHandler.h"
class MiniGamePowerState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static MiniGamePowerState* Instance() {
		return &m_MiniGamePowerState;
	}

protected:
	MiniGamePowerState() { }

private:
	/*typedef struct
	{
		SDL_Rect rect
	} arrowObjects;*/
	bool checkIfCollide(GameEngine* game, int side);
	int life;


	static MiniGamePowerState m_MiniGamePowerState;
	Player player;
	Map worldmap;
	Lightning lightning;
	Physics physics;
	InputHandler inputHandler;
	DialogHandler dialogHandler;
	DialogHandler dialogHandler2;

	GraphicHelper graphicHelper;

	int alpha;
};

#endif
