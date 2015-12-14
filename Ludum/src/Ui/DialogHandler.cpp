#include "DialogHandler.h"

void DialogHandler::Init(GameEngine* game)
{
	this->isOpen = true;
	bgImage = graphicHelper.Load_image("Data/Images/dbg.bmp", game);
	enterText = graphicHelper.GetTextString("PRESS ENTER", game->renderer, { 0, 0, 0 }, game->screenWidth - 200, game->screenHeigth - 100, 20);
}

bool DialogHandler::isDialogOpen()
{
	return this->isOpen;

}

void DialogHandler::SetOpen()
{
	this->isOpen = true;

}

void DialogHandler::Update(GameEngine* game, InputHandler* inputHandler)
{
	if (this->play)
	{
		if (dialogList[dialogPointer][textPointer].speed == -1)
		{
			if (inputHandler->keyReturn.pressed == true)
			{
				inputHandler->keyReturn.pressed = false;
				textPointer++;
				if (textPointer >= dialogList[dialogPointer].size())
				{
					play = false;
				}
			}
		}
		else
		{
		
			timeLeftToDisplay -= game->millisecondFTime;

			if (timeLeftToDisplay <= 0)
			{
				textPointer++;
				if (textPointer >= dialogList[dialogPointer].size())
				{
					play = false;
				}
				else
				{
					timeLeftToDisplay = dialogList[dialogPointer][textPointer].speed;
				}
			}
		}
	}
}

void DialogHandler::Draw(GameEngine* game)
{

	if (this->play)
	{	

		
		SDL_Rect r;
		r.x = 60;
		r.y = game->screenHeigth - 250 ;
		r.w = game->screenWidth-120;
		r.h = 200;

		SDL_RenderCopy(game->renderer, this->bgImage, NULL, &r);

		SDL_RenderCopy(game->renderer, dialogList[dialogPointer][textPointer].text, NULL, &dialogList[dialogPointer][textPointer].rect);

		if (dialogList[dialogPointer][textPointer].speed == -1)
		{
			SDL_RenderCopy(game->renderer, enterText.text, NULL, &enterText.rect);
			
		}
	}
}

void DialogHandler::DrawIntroText(GameEngine* game)
{
	if (this->play)
	{
		SDL_RenderCopy(game->renderer, dialogList[dialogPointer][textPointer].text, NULL, &dialogList[dialogPointer][textPointer].rect);
	}

}

void DialogHandler::AddDialog(GameEngine* game, string text, int dialog, int speed, SDL_Color color, int x, int y, int size)
{
	if (dialog == -1 || dialog >= dialogList.size())
	{
		vector<tObj> textList;
		GraphicHelper::textObject g_t_obj = graphicHelper.GetTextString(text, game->renderer, color, x ,y , size);

		tObj obj;
		obj.rect = g_t_obj.rect;
		obj.str_text = g_t_obj.str_text;
		obj.text = g_t_obj.text;
		obj.speed = speed;

		textList.push_back(obj);

		dialogList.push_back(textList);
	}
	else
	{
		GraphicHelper::textObject g_t_obj = graphicHelper.GetTextString(text, game->renderer, color, x, y, size);

		tObj obj;
		obj.rect = g_t_obj.rect;
		obj.str_text = g_t_obj.str_text;
		obj.text = g_t_obj.text;
		obj.speed = speed;

		dialogList[dialog].push_back(obj);

	}

}

void DialogHandler::playDialog(int dialog)
{
	if (dialog < dialogList.size())
	{
		play = true;
		dialogPointer = dialog;
		textPointer = 0;
		timeLeftToDisplay = dialogList[dialogPointer][textPointer].speed;

	}

}

void DialogHandler::Cleanup()
{
	this->dialogList.clear();

}