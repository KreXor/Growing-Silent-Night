#include "SDL2/SDL.h"
#include "../GameEngine.h"
//#include "state.h"
#include "IntroState.h"
#include "MenuState.h"
#include "WorldState.h"


MenuState MenuState::m_MenuState;
int SelectedItem;

void MenuState::Init(GameEngine* game)
{
	//soundHandler.Play(0);
	bgImage = graphicHelper.Load_image("Data/Images/mbg.bmp", game);
	graphicHelper.AddTextString("Play!", game->renderer, { 255, 255, 255 }, 550, 480, 20);
	graphicHelper.AddTextString("Options", game->renderer, { 255, 255, 255 }, 550, 510, 20);
	graphicHelper.AddTextString("Help", game->renderer, { 255, 255, 255 }, 550, 540, 20);
	graphicHelper.AddTextString("Exit", game->renderer, { 255, 255, 255 }, 550, 570, 20);
	ChangeSelectedText(game->renderer);
	inputHandler.Init();
}

void MenuState::Cleanup()
{
	graphicHelper.Cleanup();
}

void MenuState::Pause()
{
}

void MenuState::Resume()
{
	//if (option )
}

void MenuState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
}

void MenuState::Update(GameEngine* game)
{
	if (inputHandler.keyRunUp.pressed == true){
		if (selectedItem == 0)
			selectedItem = 3;
		else
			selectedItem--;

		ChangeSelectedText(game->renderer);
		inputHandler.keyRunUp.pressed = false;
	}
	else if (inputHandler.keyRunDown.pressed == true){
		if (selectedItem == 3)
			selectedItem = 0;
		else
			selectedItem++;

		ChangeSelectedText(game->renderer);
		inputHandler.keyRunDown.pressed = false;
	}

	if (inputHandler.KeyEscape.pressed == true){
		inputHandler.KeyEscape.pressed = false;
		//game->PopState();
	}

	if (inputHandler.keyReturn.pressed == true){
		if (selectedItem == 0)
		{		
			game->ChangeState(IntroState::Instance());
			inputHandler.keyReturn.pressed = false;
		}

		if (selectedItem == 3)
		{
			SDL_Quit();
			exit(1);
		}
			
	}

	
}

void MenuState::Draw(GameEngine* game)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = game->screenWidth;
	rect.h = game->screenHeigth;


	SDL_RenderCopy(game->renderer, this->bgImage,NULL, &rect);

	graphicHelper.PrintTextBuffer(game->renderer);
}

void MenuState::ChangeSelectedText(SDL_Renderer* renderer)
{

	graphicHelper.textBuffer[0] = graphicHelper.GetTextString("Play!", renderer, { 255, 255, 255 }, 580, 280, 30);
	graphicHelper.textBuffer[1] = graphicHelper.GetTextString("Options", renderer, { 255, 255, 255 }, 580, 310, 30);
	graphicHelper.textBuffer[2] = graphicHelper.GetTextString("Help", renderer, { 255, 255, 255 }, 580, 340, 30);
	graphicHelper.textBuffer[3] = graphicHelper.GetTextString("Exit", renderer, { 255, 255, 255 }, 580, 370, 30);
	
	graphicHelper.textBuffer[this->selectedItem] = graphicHelper.GetTextString(graphicHelper.textBuffer[this->selectedItem].str_text, renderer, { 255, 0, 255 }, graphicHelper.textBuffer[this->selectedItem].rect.x, graphicHelper.textBuffer[this->selectedItem].rect.y, 30);

}

