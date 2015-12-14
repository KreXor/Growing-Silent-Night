#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "SDL2/SDL.h"
#include "State.h"
#include "../Player.h"
#include "../Map/Map.h"
#include "../Physics/Physics.h"
#include "../Physics/Lightning.h"
#include "../InputHandler.h"
#include "../SoundHandler.h"
#include "../Ui/DialogHandler.h"
class IntroState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static IntroState* Instance() {
		return &m_IntroState;
	}

protected:
	IntroState() { }

private:
	SoundHandler soundHandler;
	static IntroState m_IntroState;
	Player player;
	Map worldmap;
	Lightning lightning;
	Physics physics;
	InputHandler inputHandler;
	DialogHandler dialogHandler;
	DialogHandler dialogHandler2;

	GraphicHelper graphicHelper;
	SDL_Surface* bg;
	SDL_Surface* fader;
	int alpha;
};

#endif
