#include <stdio.h>

#include "SDL2/SDL.h"
#include "../../GameEngine.h"
//#include "state.h"
#include "MiniGamePowerState.h"
#include "../WorldState.h"
#include "../../Item/Item.h"


MiniGamePowerState MiniGamePowerState::m_MiniGamePowerState;

void MiniGamePowerState::Init(GameEngine* game)
{


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

	player.position.x = 300;
	player.position.y = 500;
	player.movmentSpeed = 2;
	worldmap.LoadMap(game, "Data/Tiles/map.json");
	inputHandler.Init();
	game->camera.reset();
	game->camera.setZoomLevel(2);
	game->camera.setFocus(320, 500);

	player.direction = -1;
	player.sprite->SetCurrentBehaviour(3);
}

void MiniGamePowerState::Cleanup()
{
	dialogHandler.Cleanup();
	dialogHandler2.Cleanup();
}

void MiniGamePowerState::Pause()
{
}

void MiniGamePowerState::Resume()
{
}

void MiniGamePowerState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
	//game->ChangeState( MenuState::Instance());
}

void MiniGamePowerState::Update(GameEngine* game)
{
	

	if (inputHandler.keyRunRight.pressed == true){
		checkIfCollide(game, 0);
		inputHandler.keyRunRight.pressed = false;
	

	}

	else if (inputHandler.keyRunLeft.pressed == true){
		checkIfCollide(game, 1);
		inputHandler.keyRunLeft.pressed = false;

	}

	if (life == 1)
		life = 1;
	
}

void MiniGamePowerState::Draw(GameEngine* game)
{

	worldmap.Draw(game);
	player.Draw(game, game->millisecondFTime);
	//player.sprite->PlayAnimation();
	graphicHelper.DrawMiniGameBox(game);



}

bool MiniGamePowerState::checkIfCollide(GameEngine* game, int side)
{

	return 0;
}
