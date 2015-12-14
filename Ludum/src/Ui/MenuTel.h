#ifndef MENUTEL_H
#define MENUTEL_H

#include "../GameEngine.h"
#include "../InputHandler.h"
#include "../GraphicHelper.h"
#include "DialogHandler.h"

class MenuTel
{
private:
	bool isOpen = false;
	
	
	GraphicHelper graphicHelper;
	SDL_Texture* bgImage;
	

public:
	void Init(GameEngine* game);
	void Draw(GameEngine* game);
	void Update(GameEngine* game, Player* player, InputHandler* inputHandler);
	bool isMenuOpen();
	void SetOpen();

	bool isMemberSelected;
	int selectedItem = 0;
	DialogHandler dialogHandler;
	void CleanUp();
};

#endif
