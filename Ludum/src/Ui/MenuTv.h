#ifndef MENUTV_H
#define MENUTV_H

#include "../GameEngine.h"
#include "../InputHandler.h"
#include "../GraphicHelper.h"
#include "DialogHandler.h"

class MenuTv
{
private:
	bool isOpen = false;
	
	
	GraphicHelper graphicHelper;
	SDL_Texture* bgImage;
	DialogHandler dialogHandler;

public:
	int selectedItem = 0;
	void Init(GameEngine* game);
	void Draw(GameEngine* game);
	void Update(GameEngine* game, Player* player, InputHandler* inputHandler);
	bool isMenuOpen();
	void SetOpen();
};

#endif
