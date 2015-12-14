#ifndef DIALOGHANDLER_H
#define DIALOGHANDLER_H

#include "../GameEngine.h"
#include "../InputHandler.h"
#include "../GraphicHelper.h"
#include "vector"
class DialogHandler
{
private:
	bool isOpen = false;
	
	GraphicHelper graphicHelper;
	SDL_Texture* bgImage;

	typedef struct
	{
		SDL_Texture* text;
		SDL_Rect rect;
		std::string str_text;
		int speed;
	} tObj;

	vector < vector<tObj> > dialogList;
	//vector<textObject> dialogList;

	
	int dialogPointer = 0;
	
	float timeLeftToDisplay;
	GraphicHelper::textObject enterText;

public:
	int textPointer = 0;
	bool play = false;
	void Init(GameEngine* game);
	void AddDialog(GameEngine* game, string text, int dialog, int speed, SDL_Color color, int x, int y, int size);
	void Draw(GameEngine* game);
	void DrawIntroText(GameEngine* game);
	void Update(GameEngine* game, InputHandler* inputHandler);
	bool isDialogOpen();
	void SetOpen();
	void playDialog(int dialog);
	void Cleanup();
	
};

#endif
