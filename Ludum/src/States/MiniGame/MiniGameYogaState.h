#ifndef MINIGAMEYOGASTATE_H
#define MINIGAMEYOGASTATE_H

#include "SDL2/SDL.h"
#include "../State.h"
#include "../../Player.h"
#include "../../Map/Map.h"
#include "../../Physics/Physics.h"
#include "../../Physics/Lightning.h"
#include "../../InputHandler.h"
#include "../../Ui/DialogHandler.h"
class MiniGameYogaState : public State
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static MiniGameYogaState* Instance() {
		return &m_MiniGameYogaState;
	}

protected:
	MiniGameYogaState() { }

private:
	/*typedef struct
	{
		SDL_Rect rect
	} arrowObjects;*/
	bool checkIfCollide(GameEngine* game, int side);
	int life;
	int timeToNewArrow;
	float arrowSpeed = 2;
	float timeSinceLastArrow;
	vector<SDL_Rect> arrowList;
	static MiniGameYogaState m_MiniGameYogaState;
	Player player;
	Map worldmap;
	Lightning lightning;
	Physics physics;
	InputHandler inputHandler;
	DialogHandler dialogHandler;
	DialogHandler dialogHandler2;

	GraphicHelper graphicHelper;
	SDL_Texture* yellow_arrow;
	SDL_Texture* blue_arrow;
	int alpha;
	int arrowTaken;
};

#endif
