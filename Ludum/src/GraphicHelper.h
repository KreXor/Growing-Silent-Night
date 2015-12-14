#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <iostream>

#include "SDL2/SDL.h"
#include <string>
#include "vector"
#include "SDL2/SDL_ttf.h"
#include "GameEngine.h"

using namespace std;

class GraphicHelper
{
public:
	typedef struct
	{
		SDL_Texture* text;
		SDL_Rect rect;
		std::string str_text;
	} textObject;

	GraphicHelper();
	void AddTextString(std::string text, SDL_Renderer* renderer, SDL_Color text_color, int posX, int posY, int fontSize);
	void PrintTextBuffer(SDL_Renderer* renderer);
	void Cleanup();
	void DrawCutsceneBox(GameEngine* game);
	vector<textObject> textBuffer;
	textObject GetTextString(std::string text, SDL_Renderer* renderer, SDL_Color text_color, int posX, int posY, int fontSize);
	SDL_Texture *Load_image(string filename, GameEngine* game);
	void DrawMiniGameBox(GameEngine* game);

private:
	

	
};

#endif
