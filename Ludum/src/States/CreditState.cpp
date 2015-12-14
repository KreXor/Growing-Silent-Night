#include <stdio.h>

#include "SDL2/SDL.h"
#include "../GameEngine.h"
//#include "state.h"
#include "CreditState.h"
#include "WorldState.h"
#include "MenuState.h"
#include "../Item/Item.h"


CreditState CreditState::m_CreditState;

void CreditState::Init(GameEngine* game)
{
	soundHandler.Play(1);
	img1 = graphicHelper.Load_image("Data/Images/1.bmp", game);
	img2 = graphicHelper.Load_image("Data/Images/2.bmp", game);
	img3 = graphicHelper.Load_image("Data/Images/3.bmp", game);
	img4 = graphicHelper.Load_image("Data/Images/4.bmp", game);
	img5 = graphicHelper.Load_image("Data/Images/5.bmp", game);
	img6 = graphicHelper.Load_image("Data/Images/6.bmp", game);
	img7 = graphicHelper.Load_image("Data/Images/7.bmp", game);
	img8 = graphicHelper.Load_image("Data/Images/8.bmp", game);

	img9 = graphicHelper.Load_image("Data/Images/c1.bmp", game);
	img10 = graphicHelper.Load_image("Data/Images/c2.bmp", game);
	img11 = graphicHelper.Load_image("Data/Images/c3.bmp", game);
	img12 = graphicHelper.Load_image("Data/Images/c4.bmp", game);
	img13 = graphicHelper.Load_image("Data/Images/c5.bmp", game);
	int timer = 4000;
	int imgPointer = 0;
}

void CreditState::Cleanup()
{
	
}

void CreditState::Pause()
{
}

void CreditState::Resume()
{
}

void CreditState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
}

void CreditState::Update(GameEngine* game)
{
	timer -= game->millisecondFTime;
	if (timer <= 0 && imgPointer < 6)
	{
		imgPointer++;
		timer = 4000;

	}
	else if (timer <= 0 && imgPointer < 7)
	{
		imgPointer++;
		timer = 8000;

	}
	else if (timer <= 0 && imgPointer < 11)
	{
		imgPointer++;
		timer = 8000;
	}
	else if (timer <= 0 && imgPointer < 12)
	{
		imgPointer++;
		timer = 32000;
	}
	else if (timer <= 0 && imgPointer == 12)
	{
		SDL_Quit();
		exit(0);
	}
}

void CreditState::Draw(GameEngine* game)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = game->screenHeigth;
	rect.w = game->screenWidth;
	if (imgPointer == 0)
		SDL_RenderCopy(game->renderer, img1, NULL, &rect);
	if (imgPointer == 1)
		SDL_RenderCopy(game->renderer, img2, NULL, &rect);
	if (imgPointer == 2)
		SDL_RenderCopy(game->renderer, img3, NULL, &rect);
	if (imgPointer == 3)
		SDL_RenderCopy(game->renderer, img4, NULL, &rect);
	if (imgPointer == 4)
		SDL_RenderCopy(game->renderer, img5, NULL, &rect);
	if (imgPointer == 5)
		SDL_RenderCopy(game->renderer, img6, NULL, &rect);
	if (imgPointer == 6)
		SDL_RenderCopy(game->renderer, img7, NULL, &rect);
	if (imgPointer == 7)
		SDL_RenderCopy(game->renderer, img8, NULL, &rect);
	if (imgPointer == 8)
		SDL_RenderCopy(game->renderer, img9, NULL, &rect);
	if (imgPointer == 9)
		SDL_RenderCopy(game->renderer, img10, NULL, &rect);
	if (imgPointer == 10)
		SDL_RenderCopy(game->renderer, img11, NULL, &rect);
	if (imgPointer == 11)
		SDL_RenderCopy(game->renderer, img12, NULL, &rect);
	if (imgPointer == 12)
		SDL_RenderCopy(game->renderer, img13, NULL, &rect);


	
}
