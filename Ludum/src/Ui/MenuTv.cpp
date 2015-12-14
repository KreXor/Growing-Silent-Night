#include "MenuTv.h"

void MenuTv::Init(GameEngine* game)
{

	bgImage = graphicHelper.Load_image("Data/Images/tv.bmp", game);

	graphicHelper.AddTextString("Xanadu Beach", game->renderer, { 0, 0, 0 }, 250, 190, 20);
	graphicHelper.AddTextString("Cooking Food", game->renderer, { 0, 0, 0 }, 250, 220, 20);
	graphicHelper.AddTextString("White Bread News", game->renderer, { 0, 0, 0 }, 250, 250, 20);
	graphicHelper.AddTextString("Turn Off", game->renderer, { 0, 0, 0 }, 250, 280, 20);


	int textSize = 30;
	int texttime = 5000;
	dialogHandler.Init(game);
	dialogHandler.AddDialog(game, "Grandpa: Holy sheister! This is more painful than hemorrhoids on steroids.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: You call this entertainment? I was more entertained in Korea -52.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Kids nowadays carry those fruity devices around like evolution never happened.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Vulture necked good-for-nothing airheads.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Sitcoms? Bah, should be called shit-coms if you ask me.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Clowntarded mud-for-brains.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	
	dialogHandler.AddDialog(game, "Grandpa: I'd rather have an unsedated vasectomy than watch this crap.", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Who in their right state of mind actually enjoys this?", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: When I cook, I don't need them fancy utensils.", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: What's wrong with corn bread and chili-dogs?", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Looks like they've already eaten it. Twice.", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: You're not fooling me with that fancy crap.", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);

	dialogHandler.AddDialog(game, "Grandpa: The world is turning into an effing kindergarten.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Blah blah blah, quit mumbling loser.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Idiot.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Where's the real news? All I see is commie comedians, and they're not funny.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Asshat, I know that ain't the truth.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Grandpa: Moron. No wonder nobody trusts the government anymore.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
}

bool MenuTv::isMenuOpen()
{
	return this->isOpen;

}

void MenuTv::SetOpen()
{
	this->isOpen = true;

}

void MenuTv::Update(GameEngine* game, Player* player, InputHandler* inputHandler)
{
	dialogHandler.Update(game, inputHandler);
	player->position.x = 705;
	player->position.y = 1170;
	game->camera.setZoomLevel(2);
	game->camera.setFocus(player->position.x, player->position.y);
	if (inputHandler->keyRunUp.pressed == true){
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = 3;
		inputHandler->keyRunUp.pressed = false;
	}
	else if (inputHandler->keyRunDown.pressed == true){
		selectedItem++;
		if (selectedItem > 3)
			selectedItem = 0;
		inputHandler->keyRunDown.pressed = false;
	}

	if (inputHandler->keyReturn.pressed == true)
	{
		inputHandler->keyReturn.pressed = false;

		if (selectedItem == 0)
			dialogHandler.playDialog(0);
		if (selectedItem == 1)
			dialogHandler.playDialog(1);
		if (selectedItem == 2)
			dialogHandler.playDialog(2);
		if (selectedItem == 3)
		{
			player->position.x = 705;
			player->position.y = 1190;
			this->isOpen = false;
			dialogHandler.play = false;
			game->camera.setZoomLevel(1);
			game->camera.setFocus(player->position.x, player->position.y);
		}
		
	}

}

void MenuTv::Draw(GameEngine* game)
{
	if (this->isOpen)
	{	
		SDL_Rect r;
		r.x = 100;
		r.y = 100;
		r.w = 400;
		r.h = 300;

		SDL_RenderCopy(game->renderer, this->bgImage, NULL, &r);

	
		r.x = 220;
		r.y = 190 + this->selectedItem*30;
		r.w = 20;
		r.h = 20;

		// Set render color to blue ( rect will be rendered in this color )
		SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);

		// Render rect
		SDL_RenderFillRect(game->renderer, &r);

		graphicHelper.PrintTextBuffer(game->renderer);

		dialogHandler.Draw(game);
	}

}