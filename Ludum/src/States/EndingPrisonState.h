#ifndef ENDINGPRISONSTATE_H
#define ENDINGPRISONSTATE_H

#include "SDL2/SDL.h"
#include "State.h"
#include "../Player.h"
#include "../Map/Map.h"
#include "../Physics/Physics.h"
#include "../Physics/Lightning.h"
#include "../InputHandler.h"
#include "../Ui/DialogHandler.h"
#include "../SoundHandler.h"
class EndingPrisonState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static EndingPrisonState* Instance() {
		return &m_EndingPrisonState;
	}

protected:
	EndingPrisonState() { }

private:
	static EndingPrisonState m_EndingPrisonState;
	Player player;
	Player cellmate;
	Map worldmap;
	Lightning lightning;
	Physics physics;
	InputHandler inputHandler;
	DialogHandler dialogHandler;
	SoundHandler soundHandler;
	SDL_Texture* policeCar;
	SDL_Rect policeCarPosition;
	int policeCarSpeed;
	int cameraMoveDone;

	GraphicHelper graphicHelper;
	SDL_Surface* bg;
	SDL_Surface* fader;
	int alpha;
};

#endif
