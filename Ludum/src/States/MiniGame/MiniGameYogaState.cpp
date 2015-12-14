#include <stdio.h>

#include "SDL2/SDL.h"
#include "../../GameEngine.h"
//#include "state.h"
#include "MiniGameYogaState.h"
#include "../WorldState.h"
#include "../PlayerHouseState.h"
#include "../../Item/Item.h"
#include "../EndingPrisonState.h"


MiniGameYogaState MiniGameYogaState::m_MiniGameYogaState;

void MiniGameYogaState::Init(GameEngine* game)
{

	yellow_arrow = graphicHelper.Load_image("Data/Images/arrow_yellow.bmp", game);
	blue_arrow = graphicHelper.Load_image("Data/Images/arrow_blue.bmp", game);
	timeSinceLastArrow = 1000;
	timeToNewArrow = 1000;
	arrowSpeed = 2;
	life = 5;
	arrowTaken = 0;
/*	dialogHandler.Init(game);
	dialogHandler2.Init(game);
	int heigthPos = game->screenHeigth / 2-100;
	int widthPos = game->screenWidth / 2-170;
	SDL_Color color = { 255, 255, 255 };
	int size = 50;
	dialogHandler.AddDialog(game, "Christmas 1986", 0, 5000, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "", 0, 1000, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 1999", 0, 5000, color, widthPos, heigthPos, size);

	dialogHandler.playDialog(0);*/


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
	
	player.position.x = 420;
	player.position.y = 580;
	player.movmentSpeed = 2;
	worldmap.LoadMap(game, "Data/Tiles/yoga.json");
	inputHandler.Init();
	game->camera.reset();
	game->camera.setZoomLevel(2);
	game->camera.setFocus(player.position.x, player.position.y);

	player.direction = -1;
	player.sprite->SetCurrentBehaviour(3);
}

void MiniGameYogaState::Cleanup()
{
	dialogHandler.Cleanup();
	dialogHandler2.Cleanup();
	arrowList.clear();
}

void MiniGameYogaState::Pause()
{
}

void MiniGameYogaState::Resume()
{
}

void MiniGameYogaState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
	//game->ChangeState( MenuState::Instance());
}

void MiniGameYogaState::Update(GameEngine* game)
{
	this->timeSinceLastArrow -= game->millisecondFTime;
	if (this->timeSinceLastArrow <= 0)
	{
		SDL_Rect r;
		r.x = 0;
		r.y = 20;
		r.w = 90;
		r.h = 50;
		int dx = rand() % 2;

		if (dx == 0)
		{
			r.x = 250;
		}
		else
		{
			r.x = game->screenWidth - 340;
		}
		

		arrowList.push_back(r);
		timeSinceLastArrow = timeToNewArrow;

		arrowSpeed += 0.05;
		timeToNewArrow -= 2;
	}

	for (int i = 0; i < this->arrowList.size(); i++)
	{
		arrowList[i].y += this->arrowSpeed;

		if (arrowList[i].y > game->screenHeigth)
		{
			life--;
			arrowList.erase(arrowList.begin() + i);
		}
	}

	//dialogHandler.Update(game, &inputHandler);
	//dialogHandler2.Update(game, &inputHandler);
	game->camera.update(game->millisecondFTime);

	if (inputHandler.keyRunRight.pressed == true){
		checkIfCollide(game, 0);
		inputHandler.keyRunRight.pressed = false;
	

	}

	else if (inputHandler.keyRunLeft.pressed == true){
		checkIfCollide(game, 1);
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
			game->ChangeState(EndingPrisonState::Instance());
		else
			game->ChangeState(PlayerHouseState::Instance());
	}

	if (arrowTaken == 20)
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

void MiniGameYogaState::Draw(GameEngine* game)
{

	worldmap.Draw(game);
	player.Draw(game, game->millisecondFTime);
	player.sprite->PlayAnimation();
	graphicHelper.DrawMiniGameBox(game);


	SDL_Rect r;
	r.x = 250;
	r.y = game->screenHeigth-130;
	r.w = 90;
	r.h = 50;
	SDL_RenderCopyEx(game->renderer, this->yellow_arrow, NULL, &r, 0, NULL, SDL_FLIP_HORIZONTAL);
	
	r.x = game->screenWidth-340;
	r.y = game->screenHeigth - 130;
	SDL_RenderCopy(game->renderer, this->yellow_arrow, NULL, &r);
	

	for (int i = 0; i < this->arrowList.size(); i++)
	{
		if (arrowList[i].x < 300)
			SDL_RenderCopyEx(game->renderer, this->blue_arrow, NULL, &arrowList[i], 0, NULL, SDL_FLIP_HORIZONTAL);
		else
			SDL_RenderCopy(game->renderer, this->blue_arrow, NULL, &arrowList[i]);

	}

}

bool MiniGameYogaState::checkIfCollide(GameEngine* game, int side)
{
	for (int i = 0; i < this->arrowList.size(); i++)
	{
		if (side == 1 && arrowList[i].x < 300 && arrowList[i].y > game->screenHeigth - 170 && arrowList[i].y)
		{
			arrowTaken++;
			arrowList.erase(arrowList.begin() + i);
			player.sprite->SetCurrentBehaviour(5);
			player.direction = 1;
			return true;

		}
		if (side == 0 && arrowList[i].x > 300 && arrowList[i].y > game->screenHeigth - 170 && arrowList[i].y)
		{
			arrowTaken++;
			arrowList.erase(arrowList.begin() + i);
			player.sprite->SetCurrentBehaviour(5);
			player.direction = -1;
			return true;
		}
	}

	life--;
	return 0;
}
