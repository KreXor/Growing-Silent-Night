#ifndef GAMEENGINE_H
#define GAMEENGINE_H


#include "Camera.h"
#include "SDL2/SDL.h"
#include <vector>
#include "SDL2/SDL_ttf.h"



using namespace std;

class State;

class GameEngine
{
public:

	void Init(const char* title, int width=640, int height=480,
		      int bpp=0, bool fullscreen=false);
	void Cleanup();

	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	//GraphicHelper graphicHelper;
	SDL_Surface* screen;
	SDL_Renderer* renderer;
	SDL_Window* window;

	int screenWidth;
	int screenHeigth;


	float millisecondFTime;

	Camera camera;

	bool neighbour1_Played = false;
	bool neighbour2_Played = false;
	bool neighbour3_Played = false;
	bool neighbour4_Played = false;

	bool neighbour1_Completed = false;
	bool neighbour2_Completed = false;
	bool neighbour3_Completed = false;
	bool neighbour4_Completed = false;

	bool usableChar_Vicky = true;
	bool usableChar_Hayden = true;
	bool usableChar_Rocco = true;
	bool usableChar_Otter = true;
	bool isStart = true;
	int usableChar_selected = 0;

	int neighbour_Selected = 0;

private:
	// the stack of states
	vector<State*> states;

	bool m_running;
	bool m_fullscreen;
};

#endif
