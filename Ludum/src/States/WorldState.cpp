#include <stdio.h>

#include "SDL2/SDL.h"
#include "../GameEngine.h"
//#include "state.h"
#include "WorldState.h"
#include "../Player.h"
#include "MenuState.h"
#include <stdlib.h> 
#include "MiniGame/MiniGameYogaState.h"
#include "MiniGame/MiniGamePetState.h"
#include "MiniGame/MiniGamePowerState.h"


WorldState WorldState::m_WorldState;

bool play = false;

void WorldState::Init(GameEngine* game)
{
	map = graphicHelper.Load_image("Data/Images/minimap.bmp", game);
	yellow_arrow = graphicHelper.Load_image("Data/Images/arrow_yellow.bmp", game);
	ximg = graphicHelper.Load_image("Data/Images/ui_cross.bmp", game);

	arrowPos.x = 200;
	arrowPos.y = 100;
	arrowPos.w = 150;
	arrowPos.h = 100;

	mapPos.x = 0;
	mapPos.y = 0;
	mapPos.w = game->screenWidth;
	mapPos.h = game->screenHeigth;

	inputHandler.Init();
}

void WorldState::Cleanup()
{
	graphicHelper.Cleanup();
}

void WorldState::Pause()
{
}

void WorldState::Resume()
{


}

void WorldState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
}

void WorldState::Update(GameEngine* game)
{
	if (inputHandler.keyRunRight.pressed == true){
		if (arrowPos.x < 500)
			arrowPos.x = 650;
	}

	else if (inputHandler.keyRunLeft.pressed == true){
		if (arrowPos.x > 500)
			arrowPos.x = 200;
	}
	else if (inputHandler.keyRunUp.pressed == true){
		if (arrowPos.y > 300)
			arrowPos.y = 100;

	}
	else if (inputHandler.keyRunDown.pressed == true){
		if (arrowPos.y < 300)
			arrowPos.y = 400;
	}

	if (inputHandler.keyReturn.pressed == true)
	{
		inputHandler.keyReturn.pressed = false;
		if (arrowPos.x < 500 && arrowPos.y < 300 && !game->neighbour1_Played)
		{
			game->neighbour1_Played = true;
			game->neighbour_Selected = 1;
			game->ChangeState(MiniGameYogaState::Instance());
		}

		if (arrowPos.x > 500 && arrowPos.y < 300 && !game->neighbour2_Played)
		{
			game->neighbour2_Played = true;
			game->neighbour_Selected = 2;
			game->ChangeState(MiniGamePetState::Instance());
		}
		if (arrowPos.x < 500 && arrowPos.y > 300 && !game->neighbour3_Played)
		{
			game->neighbour3_Played = true;
			game->neighbour_Selected = 3;
			game->ChangeState(MiniGameYogaState::Instance());
		}

		if (arrowPos.x > 500 && arrowPos.y > 300 && !game->neighbour4_Played)
		{
			game->neighbour4_Played = true;
			game->neighbour_Selected = 4;
			game->ChangeState(MiniGamePetState::Instance());
		}
	}
}

void WorldState::Draw(GameEngine* game)
{
	SDL_RenderCopy(game->renderer, this->map, NULL, &this->mapPos);
	

	SDL_Rect rect;
	rect.w = 300;
	rect.h = 300;
	if (game->neighbour1_Played)
	{
		
		rect.x = 250;
		rect.y = 20;
		SDL_RenderCopy(game->renderer, this->ximg, NULL, &rect);
	}
	if (game->neighbour2_Played)
	{
		rect.x = 700;
		rect.y = 20;
		SDL_RenderCopy(game->renderer, this->ximg, NULL, &rect);
	}
	if (game->neighbour3_Played)
	{
		rect.x = 200;
		rect.y = 400;
		SDL_RenderCopy(game->renderer, this->ximg, NULL, &rect);
	}
	if (game->neighbour4_Played)
	{
		rect.x = 700;
		rect.y = 370;
		SDL_RenderCopy(game->renderer, this->ximg, NULL, &rect);
	}

	SDL_RenderCopy(game->renderer, this->yellow_arrow, NULL, &this->arrowPos);

}

