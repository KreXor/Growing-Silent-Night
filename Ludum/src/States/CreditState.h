#ifndef CREDITSTATE_H
#define CREDITSTATE_H

#include "SDL2/SDL.h"
#include "State.h"
#include "../Player.h"
#include "../Map/Map.h"
#include "../Physics/Physics.h"
#include "../Physics/Lightning.h"
#include "../InputHandler.h"
#include "../Ui/DialogHandler.h"
#include "../SoundHandler.h"
class CreditState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static CreditState* Instance() {
		return &m_CreditState;
	}

protected:
	CreditState() { }

private:
	static CreditState m_CreditState;
	SoundHandler soundHandler;
	GraphicHelper graphicHelper;
	InputHandler inputHandler;

	SDL_Texture* img1;
	SDL_Texture* img2;
	SDL_Texture* img3;
	SDL_Texture* img4;
	SDL_Texture* img5;
	SDL_Texture* img6;
	SDL_Texture* img7;
	SDL_Texture* img8;
	SDL_Texture* img9;
	SDL_Texture* img10;
	SDL_Texture* img11;
	SDL_Texture* img12;
	SDL_Texture* img13;

	int timer;
	int imgPointer;
};

#endif
