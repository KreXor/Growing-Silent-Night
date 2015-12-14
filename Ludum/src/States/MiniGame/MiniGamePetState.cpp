#include <stdio.h>

#include "SDL2/SDL.h"
#include "../../GameEngine.h"
//#include "state.h"
#include "MiniGamePetState.h"
#include "../WorldState.h"
#include "../PlayerHouseState.h"
#include "../EndingPrisonState.h"
#include "../../Item/Item.h"


MiniGamePetState MiniGamePetState::m_MiniGamePetState;

void MiniGamePetState::Init(GameEngine* game)
{
	bar_blue = graphicHelper.Load_image("Data/Images/bar_blue.bmp", game);
	bar_bot = graphicHelper.Load_image("Data/Images/bar_bot.bmp", game);
	bar_delimeter = graphicHelper.Load_image("Data/Images/bar_delimeter.bmp", game);
	bar_green = graphicHelper.Load_image("Data/Images/bar_green.bmp", game);
	bar_red = graphicHelper.Load_image("Data/Images/bar_red.bmp", game);
	bar_top = graphicHelper.Load_image("Data/Images/bar_top.bmp", game);
	yellow_arrow = graphicHelper.Load_image("Data/Images/arrow_yellow.bmp", game);
	bar_top_empty = graphicHelper.Load_image("Data/Images/bar_top_empty.bmp", game);

	powerBlueHeigth = 0;
	powerEmptyHeigth = 600;
	powerIncrease = 200;
	arrowTaken = 0;
	arrowDirection = 0;

	arrowPosition.x = 250;
	arrowPosition.y = game->screenHeigth-70;
	arrowPosition.w = 100;
	arrowPosition.h = 50;

	arrowSpeed = 2;
	delimeterHeigth = 5;
	blueHeigth = 250;
	greenHeigth = 100;
	redHeigth = 250;

	life = 5;

	if (game->usableChar_selected == 0)
	{
		player.Initialize(game, "Data/animation_aerobic.json");
	}
	if (game->usableChar_selected == 1)
	{
		player.Initialize(game, "Data/animation_sales.json");
	}
	if (game->usableChar_selected == 2)
	{
		player.Initialize(game, "Data/animation_grandson.json");
	}
	if (game->usableChar_selected == 3)
	{
		player.Initialize(game, "Data/animation_dressed_dude.json");
	}

	player.position.x = 415;
	player.position.y = 700;
	player.movmentSpeed = 2;
	worldmap.LoadMap(game, "Data/Tiles/dog.json");
	inputHandler.Init();
	game->camera.reset();
	game->camera.setZoomLevel(2);
	game->camera.setFocus(player.position.x, player.position.y);

	player.direction = -1;
	player.sprite->SetCurrentBehaviour(5);
}

void MiniGamePetState::Cleanup()
{
	
}

void MiniGamePetState::Pause()
{
}

void MiniGamePetState::Resume()
{
}

void MiniGamePetState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
	//game->ChangeState( MenuState::Instance());



}

void MiniGamePetState::Update(GameEngine* game)
{
	
	if (arrowDirection == 0)
	{
		arrowPosition.y += arrowSpeed;

		if (arrowPosition.y >= (game->screenHeigth - 75))
		{
			arrowDirection = 1;
		}
	}
	if (arrowDirection == 1)
	{
		arrowPosition.y -= arrowSpeed;

		if (arrowPosition.y <= (game->screenHeigth - 75 - blueHeigth - greenHeigth - redHeigth))
		{
			arrowDirection = 0;
		}
	}

	game->camera.update(game->millisecondFTime);

	if (inputHandler.keyRunRight.pressed == true){
		if (powerBlueHeigth >= 600)
		{
			powerBlueHeigth = 0;
			powerEmptyHeigth = 600;
			arrowSpeed -= 2;
		}
		inputHandler.keyRunRight.pressed = false;
	}

	else if (inputHandler.keyRunLeft.pressed == true){
		if (checkIfCollide(game, 1))
		{
			if (powerBlueHeigth <= 600)
			{
				powerBlueHeigth += powerIncrease;
				powerEmptyHeigth -= powerIncrease;
				
			}
			arrowSpeed += 1;
			arrowTaken++;
		}
		else
		{
			life--;
		}
		inputHandler.keyRunLeft.pressed = false;

	}	

	if (life == 0)
	{
		if (game->neighbour_Selected == 1)
			game->neighbour1_Completed = false;
		if (game->neighbour_Selected == 2)
			game->neighbour1_Completed = false;
		if (game->neighbour_Selected == 3)
			game->neighbour1_Completed = false;
		if (game->neighbour_Selected == 4)
			game->neighbour1_Completed = false;

		if (game->neighbour1_Played && game->neighbour2_Played && game->neighbour3_Played && game->neighbour4_Played)
			game->PushState(EndingPrisonState::Instance());
		else
			game->ChangeState(PlayerHouseState::Instance());
	}
	
	if (arrowTaken == 10)
	{
		if (game->neighbour_Selected == 1)
			game->neighbour1_Completed = true;
		if (game->neighbour_Selected == 2)
			game->neighbour1_Completed = true;
		if (game->neighbour_Selected == 3)
			game->neighbour1_Completed = true;
		if (game->neighbour_Selected == 4)
			game->neighbour1_Completed = true;

		if (game->neighbour1_Played && game->neighbour2_Played && game->neighbour3_Played && game->neighbour4_Played)
			game->ChangeState(EndingPrisonState::Instance());
		else
			game->ChangeState(PlayerHouseState::Instance());
	}
}

void MiniGamePetState::Draw(GameEngine* game)
{

	worldmap.Draw(game);
	player.Draw(game, game->millisecondFTime);
	player.sprite->PlayAnimation();
	graphicHelper.DrawMiniGameBox(game);

	int width = 12*3;
	SDL_Rect r;
	r.x = 200;
	r.y = game->screenHeigth-50;
	r.w = width;
	r.h = 3;
	SDL_RenderCopy(game->renderer, this->bar_bot, NULL, &r);

	
	r.y = game->screenHeigth - 50 - blueHeigth;
	r.h = blueHeigth;
	SDL_RenderCopy(game->renderer, this->bar_blue, NULL, &r);


	r.y = game->screenHeigth - 50 - blueHeigth - delimeterHeigth;
	r.h = delimeterHeigth;
	SDL_RenderCopy(game->renderer, this->bar_delimeter, NULL, &r);

	
	r.y = game->screenHeigth - 50 - blueHeigth - delimeterHeigth - greenHeigth;
	r.h = greenHeigth;
	SDL_RenderCopy(game->renderer, this->bar_green, NULL, &r);

	r.y = game->screenHeigth - 50 - blueHeigth - delimeterHeigth - greenHeigth - delimeterHeigth;
	r.h = delimeterHeigth;
	SDL_RenderCopy(game->renderer, this->bar_delimeter, NULL, &r);


	r.y = game->screenHeigth - 50 - blueHeigth - delimeterHeigth - greenHeigth - delimeterHeigth - redHeigth;
	r.h = redHeigth;
	SDL_RenderCopy(game->renderer, this->bar_red, NULL, &r);

	r.y = game->screenHeigth - 50 - blueHeigth - delimeterHeigth - greenHeigth - delimeterHeigth - redHeigth-3;
	r.h = 3;
	SDL_RenderCopy(game->renderer, this->bar_top, NULL, &r);
	
	SDL_RenderCopyEx(game->renderer, this->yellow_arrow, NULL, &arrowPosition, 0, NULL, SDL_FLIP_HORIZONTAL);

	if (powerBlueHeigth >= 600)
	{
		r.x = game->screenWidth-350;
		r.y = game->screenHeigth - 150;
		r.w = 100;
		r.h = 50;
		SDL_RenderCopy(game->renderer, this->yellow_arrow, NULL, &r);
	}






	r.x = game->screenWidth-200;
	r.y = game->screenHeigth - 50;
	r.w = width;
	r.h = 3;
	SDL_RenderCopy(game->renderer, this->bar_bot, NULL, &r);


	r.y = game->screenHeigth - 50 - powerBlueHeigth;
	r.h = powerBlueHeigth;
	SDL_RenderCopy(game->renderer, this->bar_blue, NULL, &r);

	r.y = game->screenHeigth - 50 - powerBlueHeigth - powerEmptyHeigth;
	r.h = powerEmptyHeigth;
	SDL_RenderCopy(game->renderer, this->bar_delimeter, NULL, &r);

	r.y = game->screenHeigth - 50 - powerBlueHeigth - powerEmptyHeigth - 3;
	r.h = 3;
	SDL_RenderCopy(game->renderer, this->bar_top_empty, NULL, &r);

}

bool MiniGamePetState::checkIfCollide(GameEngine* game, int side)
{
	if (side == 1)
	{
		if (arrowPosition.y < (game->screenHeigth - 50 - blueHeigth - delimeterHeigth) && arrowPosition.y >(game->screenHeigth - 50 - blueHeigth - delimeterHeigth - greenHeigth - delimeterHeigth))
		{
			
			
			return true;
		}
			
	}
	return false;
}
