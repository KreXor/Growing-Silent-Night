#include "GameEngine.h"
#include "States/WorldState.h"
#include "States/MenuState.h"
#include "States/IntroState.h"
#include "States/PlayerHouseState.h"
#include "States/EndingPrisonState.h"
#include "States/CreditState.h"
#include "States/MiniGame/MiniGameYogaState.h"
#include "States/MiniGame/MiniGamePetState.h"
#include "States/MiniGame/MiniGamePowerState.h"
#include "Player.h"
#include <string>

#define WIDTH 1280
#define HEIGHT 720

#define TICK_INTERVAL 20

Uint32 TimeLeft(void)
{
    static Uint32 next_time = 0;
    Uint32 now;

    now = SDL_GetTicks();
    if ( next_time <= now ) {
        next_time = now+TICK_INTERVAL;
        return(0);
    }
    return(next_time-now);
}

int main ( int argc, char *argv[] )
{
	GameEngine game;

	game.Init( "The game", WIDTH, HEIGHT,32,false);

	game.ChangeState(MenuState::Instance());
	//game.ChangeState(WorldState::Instance());
	//game.ChangeState(IntroState::Instance());
	//game.ChangeState(MiniGameYogaState::Instance());
	//game.ChangeState(MiniGamePetState::Instance());
	//game.ChangeState(MiniGamePowerState::Instance());
	//game.ChangeState(PlayerHouseState::Instance());
	//game.ChangeState(EndingPrisonState::Instance());
	//game.ChangeState(CreditState::Instance());
	Uint32 old_time, current_time;
	current_time = SDL_GetTicks();

	bool quit = true;
    int ic = 0;


	while ( quit )
	{
        ic++;
        std::string tmp = std::to_string((float)ic/(SDL_GetTicks()/1000));
        //SDL_SetWindowTitle(game.window, tmp.c_str());
		//Get time since last frame.
		old_time = current_time;
		current_time = SDL_GetTicks();
		game.millisecondFTime = (current_time - old_time);

		SDL_SetRenderDrawColor( game.renderer, 0, 0, 0, 255 );
		SDL_RenderClear(game.renderer);

		game.HandleEvents();
		game.Update();
		game.Draw();


		SDL_RenderPresent(game.renderer);
		SDL_Delay(TimeLeft());


	}

	game.Cleanup();

	return 0;
}
