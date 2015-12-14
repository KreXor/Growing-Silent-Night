#include <stdio.h>

#include "SDL2/SDL.h"
#include "../GameEngine.h"
//#include "state.h"
#include "IntroState.h"
#include "WorldState.h"
#include "PlayerHouseState.h"
#include "../Item/Item.h"


IntroState IntroState::m_IntroState;

void IntroState::Init(GameEngine* game)
{
	dialogHandler.Init(game);
	dialogHandler2.Init(game);
	int heigthPos = game->screenHeigth / 2-100;
	int widthPos = game->screenWidth / 2-170;
	SDL_Color color = { 255, 255, 255 };
	int size = 50;
	dialogHandler.AddDialog(game, "Christmas 1986", 0, 4000, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "", 0, 1000, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 1989", 0, 4000, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "", 0, 1000, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 1992", 0, 4000, color, widthPos, heigthPos, size);

	dialogHandler.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 1998", 0, 2000, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 2002", 0, 2000, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 2006", 0, 2000, color, widthPos, heigthPos, size);

	dialogHandler.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 2012", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 2013", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 2014", 0, 500, color, widthPos, heigthPos, size);

	dialogHandler.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler.AddDialog(game, "Christmas 2015", 0, 5000, color, widthPos, heigthPos, size);

	heigthPos = game->screenHeigth / 2 -40;
	widthPos = game->screenWidth / 2 - 400;
	dialogHandler2.AddDialog(game, "", 0, 1000, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They accidentally burned down my tree...", 0, 3000, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 1000, color, widthPos, heigthPos, size);

	dialogHandler2.AddDialog(game, "", 0, 1000, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They unintentionally ran over my dog...", 0,3000, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 1000, color, widthPos, heigthPos, size);

	dialogHandler2.AddDialog(game, "", 0, 1000, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They unwittingly blew up my stamp collection...", 0, 3000, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);

	dialogHandler2.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They electrocuted my garden gnome...", 0, 1500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);

	dialogHandler2.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They made me miss the rerun of \"Believe it or not\"...", 0, 1500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);

	dialogHandler2.AddDialog(game, "", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They made me remember Richard Nixon...", 0, 1500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);



	dialogHandler2.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They dug through the mains pipe to my house...", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);

	dialogHandler2.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They started a huge brawl right outside my yard...", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);

	dialogHandler2.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "They intentionally sang out of tune...", 0, 250, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "", 0, 250, color, widthPos, heigthPos, size);

	widthPos = game->screenWidth / 2 - 200;
	dialogHandler2.AddDialog(game, "", 0, 2000, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, ".", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "..", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "...", 0, 500, color, widthPos, heigthPos, size);
	dialogHandler2.AddDialog(game, "... It's payback time!", 0, 1500, color, widthPos, heigthPos, size);

	dialogHandler.playDialog(0);
	dialogHandler2.playDialog(0);


	player.Initialize(game, "Data/animation.json");
	player.position.x = -200;
	player.position.y = 450;
	player.movmentSpeed = 2;
	worldmap.LoadMap(game, "Data/Tiles/map.json");
	inputHandler.Init();
	game->camera.reset();
	game->camera.setZoomLevel(2);
	game->camera.setFocus(320, 500);
	game->camera.moveCameraToCenter(900,500,9000);
	graphicHelper.AddTextString("A long time ago, in a galaxy far far away!", game->renderer, { 255, 255, 255 }, game->screenWidth/3+40, game->screenHeigth-100, 20);
	lightning.Init(game);
}

void IntroState::Cleanup()
{
	dialogHandler.Cleanup();
	dialogHandler2.Cleanup();
}

void IntroState::Pause()
{
}

void IntroState::Resume()
{
}

void IntroState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
	//game->ChangeState( MenuState::Instance());
}

void IntroState::Update(GameEngine* game)
{
	dialogHandler.Update(game, &inputHandler);
	dialogHandler2.Update(game, &inputHandler);
	game->camera.update(game->millisecondFTime);

	if (player.position.x < 880)
	{
		player.position.x += player.movmentSpeed;
		player.direction = 1;
		player.sprite->SetCurrentBehaviour(2);
	}
	else
	{
		player.position.y += player.movmentSpeed;
		player.direction = -1;
		player.sprite->SetCurrentBehaviour(4);
	}


	if (inputHandler.KeyEscape.pressed == true){
		inputHandler.KeyEscape.pressed = false;
		//soundHandler.Stop();
		game->ChangeState(PlayerHouseState::Instance());
		
	}
}

void IntroState::Draw(GameEngine* game)
{

	//worldmap.Draw(game);
	//player.Draw(game, game->millisecondFTime);
	//player.sprite->PlayAnimation();
	//graphicHelper.DrawCutsceneBox(game);

	
	dialogHandler.DrawIntroText(game);
	dialogHandler2.DrawIntroText(game);
	//graphicHelper.PrintTextBuffer(game->renderer);

	if (!dialogHandler.play)
	{
		//soundHandler.Stop();
		game->ChangeState(PlayerHouseState::Instance());
	}
		

	
}
