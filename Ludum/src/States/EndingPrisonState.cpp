#include <stdio.h>

#include "SDL2/SDL.h"
#include "../GameEngine.h"
//#include "state.h"
#include "EndingPrisonState.h"
#include "WorldState.h"
#include "CreditState.h"
#include "MenuState.h"
#include "../Item/Item.h"


EndingPrisonState EndingPrisonState::m_EndingPrisonState;

void EndingPrisonState::Init(GameEngine* game)
{

	//soundHandler.Play(0);
	dialogHandler.Init(game);
	cameraMoveDone = -1;

	int heigthPos = game->screenHeigth - 220;
	int widthPos = 90;
	SDL_Color color = { 0, 0, 0 };
	int size = 16;
	int textspeed = -1;
	dialogHandler.AddDialog(game, "Gramps: Finally, some peace and quiet!", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Gramps: All these years putting up with piles of loudmouthed lamebrains. Time to relax, get some rest and perhaps read my book. This is gonna be the best Christmas ev-", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Soapdropper: Hey-ey-eyy! Looks like we're cellmates.", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Gramps: W-what!", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Soapdropper: I'm really scared of the dark, so I asked them to put me with someone who'd make me feel comfortable. Someone who'd love to listen to my monologues.", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Gramps: Monologues? Now wait a sec-", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Soapdropper: Oh yeah I'm all into acting and singing and all kinds of artsy stuff.", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Soapdropper: I'm gonna be famous and perform on the big stage! All I need is practice, and lots of it, yessiree!!", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Gramps: The... pain...", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Soapdropper: Oh! And we can play hide and seek, and have pillowfights and... and...", 0, textspeed, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Gramps: Let me just slip into something more comfortable, like a coma.", 0, textspeed, color, widthPos, heigthPos, size);

	policeCar = graphicHelper.Load_image("Data/Images/police_car.bmp", game);
	policeCarPosition.x = -100;
	policeCarPosition.y = 340;
	policeCarPosition.w = 200;
	policeCarPosition.h = 100;
	policeCarSpeed = 3;

	player.Initialize(game, "Data/animation.json");
	cellmate.Initialize(game, "Data/animation_cellmate.json");
	player.position.x = 500;
	player.position.y = 900;
	player.movmentSpeed = 2;
	player.sprite->SetCurrentBehaviour(5);
	worldmap.LoadMap(game, "Data/Tiles/prison.json");
	inputHandler.Init();
}

void EndingPrisonState::Cleanup()
{
	dialogHandler.Cleanup();
}

void EndingPrisonState::Pause()
{
}

void EndingPrisonState::Resume()
{
}

void EndingPrisonState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
	//game->ChangeState( MenuState::Instance());
}

void EndingPrisonState::Update(GameEngine* game)
{
	dialogHandler.Update(game, &inputHandler);

	game->camera.update(game->millisecondFTime);

	if (policeCarPosition.x < 2000)
	{
		policeCarPosition.x += policeCarSpeed;
	}
	
	if (inputHandler.KeyEscape.pressed == true){
		inputHandler.KeyEscape.pressed = false;
		game->ChangeState(MenuState::Instance());
		
	}
	if (cameraMoveDone == -1)
	{
		cellmate.position.x = 700;
		cellmate.position.y = 1100;
		cellmate.sprite->SetCurrentBehaviour(3);
		cameraMoveDone++;
		game->camera.reset();
		game->camera.setZoomLevel(2);
		game->camera.setFocus(320, 350);
		game->camera.moveCameraToCenter(660, 350, 6000);
	}
	if (game->camera.checkIfMoveCompleted() && cameraMoveDone == 0)
	{
		cameraMoveDone++;
		game->camera.moveCameraToCenter(660, 950, 4000);
	}

	if (game->camera.checkIfMoveCompleted() && cameraMoveDone == 1)
	{
		cameraMoveDone++;
		dialogHandler.playDialog(0);
	}

	if (cameraMoveDone == 2)
	{
		if (dialogHandler.textPointer > 1)
		{
			if (cellmate.position.y > 900)
			{
				cellmate.position.y--;
			}
			else
			{
				cellmate.sprite->SetCurrentBehaviour(5);
			}
		}
		if (dialogHandler.play == false)
		{
			//soundHandler.Stop();
			game->ChangeState(CreditState::Instance());
		}

	}
}

void EndingPrisonState::Draw(GameEngine* game)
{

	worldmap.Draw(game);
	player.Draw(game, game->millisecondFTime);
	cellmate.Draw(game, game->millisecondFTime);
	
	player.sprite->PlayAnimation();
	cellmate.sprite->PlayAnimation();
		
		graphicHelper.DrawCutsceneBox(game);

	
	dialogHandler.Draw(game);
	SDL_RenderCopy(game->renderer, this->policeCar, NULL, &this->policeCarPosition);
	//graphicHelper.PrintTextBuffer(game->renderer);

	
		//game->ChangeState(PlayerHouseState::Instance());

	
}
