#include "Menu.h"

void Menu::Init(GameEngine* game)
{

	bgImage = graphicHelper.Load_image("Data/Images/mbg.bmp", game);
}

bool Menu::isMenuOpen()
{
	return this->isOpen;

}

void Menu::SetOpen()
{
	this->isOpen = true;

}

void Menu::Update(InputHandler* inputHandler)
{

	if (inputHandler->keyRunUp.pressed == true){
		selectedItem--;
		inputHandler->keyRunUp.pressed = false;
	}
	else if (inputHandler->keyRunDown.pressed == true){
		selectedItem++;
		inputHandler->keyRunDown.pressed = false;
	}

	if (inputHandler->keyOpenMenu.pressed == true){
		this->isOpen = false;
		inputHandler->keyOpenMenu.pressed = false;
	}

}

void Menu::Draw(GameEngine* game)
{
	if (this->isOpen)
	{	
		SDL_Rect r;
		r.x = 100;
		r.y = 100;
		r.w = 100;
		r.h = 200;

		SDL_RenderCopy(game->renderer, this->bgImage, NULL, &r);

	
		r.x = 150;
		r.y = 120 + this->selectedItem*20;
		r.w = 20;
		r.h = 20;

		// Set render color to blue ( rect will be rendered in this color )
		SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);

		// Render rect
		SDL_RenderFillRect(game->renderer, &r);


	}

}