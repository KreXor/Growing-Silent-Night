#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "SDL2/SDL.h"
#include "State.h"
#include "../InputHandler.h"
#include "../SoundHandler.h"

class MenuState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static MenuState* Instance() {
		return &m_MenuState;
	}

protected:
	MenuState() { }

private:
	static MenuState m_MenuState;

	SoundHandler soundHandler;
	InputHandler inputHandler;
	GraphicHelper graphicHelper;
	SDL_Surface* bg;
	SDL_Surface* fader;
	int alpha;
	int selectedItem = 0;
	void ChangeSelectedText(SDL_Renderer* renderer);
	SDL_Texture* bgImage;
};

#endif
