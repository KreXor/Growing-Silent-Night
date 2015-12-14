#ifndef MENU_H
#define MENU_H

#include "../GameEngine.h"
#include "../InputHandler.h"
#include "../GraphicHelper.h"
class Menu
{
private:
	bool isOpen = false;
	
	int selectedItem = 0;
	GraphicHelper graphicHelper;
	SDL_Texture* bgImage;

public:
	void Init(GameEngine* game);
	void Draw(GameEngine* game);
	void Update(InputHandler* inputHandler);
	bool isMenuOpen();
	void SetOpen();
};

#endif
