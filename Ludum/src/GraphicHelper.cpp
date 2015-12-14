
#include "GraphicHelper.h"

GraphicHelper::GraphicHelper()
{
	
}

void GraphicHelper::AddTextString(std::string text, SDL_Renderer* renderer, SDL_Color text_color, int posX, int posY, int fontSize)
{
	TTF_Font* Sans = TTF_OpenFont("Data/Fonts/Karmakooma.ttf", fontSize);

	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(Sans, text.c_str() , text_color); 
	
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	
	SDL_Rect Message_rect; 
	Message_rect.x = posX;  
	Message_rect.y = posY;
	SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);

	textObject obj;
	obj.text = Message;
	obj.rect = Message_rect;

	textBuffer.push_back(obj);
}

GraphicHelper::textObject GraphicHelper::GetTextString(std::string text, SDL_Renderer* renderer, SDL_Color text_color, int posX, int posY, int fontSize)
{
	TTF_Font* Sans = TTF_OpenFont("Data/Fonts/Karmakooma.ttf", fontSize);

	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(Sans, text.c_str(), text_color);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);


	SDL_Rect Message_rect;
	
	Message_rect.x = posX;
	Message_rect.y = posY;
	SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);

	textObject obj;
	obj.text = Message;
	obj.rect = Message_rect;
	obj.str_text = text;

	return obj;
}

void GraphicHelper::PrintTextBuffer(SDL_Renderer* renderer)
{
	for (int i = 0; i < textBuffer.size(); i++)
	{
		SDL_RenderCopy(renderer, textBuffer[i].text, NULL, &textBuffer[i].rect);
	}
	
}

void GraphicHelper::Cleanup()
{
	textBuffer.clear();

}

void GraphicHelper::DrawCutsceneBox(GameEngine* game)
{

	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = game->screenWidth;
	r.h = 150;

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

	// Render rect
	SDL_RenderFillRect(game->renderer, &r);

	r.x = 0;
	r.y = game->screenHeigth - 150;
	r.w = game->screenWidth;
	r.h = 150;

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

	// Render rect
	SDL_RenderFillRect(game->renderer, &r);
}

void GraphicHelper::DrawMiniGameBox(GameEngine* game)
{

	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = 400;
	r.h = game->screenHeigth;

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

	// Render rect
	SDL_RenderFillRect(game->renderer, &r);

	r.x = game->screenWidth-400;
	r.y = 0;
	r.w = 400;
	r.h = game->screenHeigth;

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

	// Render rect
	SDL_RenderFillRect(game->renderer, &r);
}


SDL_Texture *GraphicHelper::Load_image(string filename, GameEngine* game)
{
	SDL_Surface* loaded_image = NULL;

	if (filename.c_str() == NULL)
	{
		return NULL;
	}

	loaded_image = SDL_LoadBMP(filename.c_str());

	if (loaded_image == NULL)
	{
		return NULL;
	}

	Uint32 colorkey = SDL_MapRGB(loaded_image->format, 255, 0, 255);

	SDL_SetColorKey(loaded_image, SDL_RLEACCEL | SDL_TRUE, colorkey);


	SDL_Texture *bitmapTex = SDL_CreateTextureFromSurface(game->renderer, loaded_image);

	SDL_FreeSurface(loaded_image);
	return bitmapTex;
}