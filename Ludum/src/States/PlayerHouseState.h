#ifndef PLAYERHOUSESTATE_H
#define PLAYERHOUSESTATE_H

#include "SDL2/SDL.h"
#include "State.h"
#include "../Player.h"
#include "../Map/Map.h"
#include "../Physics/Physics.h"
#include "../Physics/Lightning.h"
#include "../InputHandler.h"
#include "../Ui/Menu.h"
#include "../Ui/MenuTv.h"
#include "../Ui/MenuTel.h"
#include "../Ui/DialogHandler.h"
#include "../SoundHandler.h"

class PlayerHouseState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static PlayerHouseState* Instance() {
		return &m_PlayerHouseState;
	}



protected:
	PlayerHouseState() { }


private:
	SoundHandler soundHandler;
	Player usableChar;
	Player player;
	Map worldmap;
	Lightning lightning;
	Physics physics;
	InputHandler inputHandler;
	static PlayerHouseState m_PlayerHouseState;
	GraphicHelper graphicHelper;
	MenuTv menuTv;
	MenuTel menuTel;
	DialogHandler dialogHandler;

	bool waitbox;
	int waitboxTimer;
	SDL_Surface* bg;
	SDL_Surface* map;
	SDL_Surface* fader;
	int alpha;

	bool changeToMinimap;
};

#endif
