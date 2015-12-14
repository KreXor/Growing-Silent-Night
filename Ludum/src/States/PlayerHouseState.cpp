#include <stdio.h>

#include "SDL2/SDL.h"
#include "../GameEngine.h"
//#include "state.h"
#include "WorldState.h"
#include "../Player.h"
#include "PlayerHouseState.h"
#include "EndingPrisonState.h"
#include <stdlib.h> 


PlayerHouseState PlayerHouseState::m_PlayerHouseState;

//bool play = false;

void PlayerHouseState::Init(GameEngine* game)
{
	menuTv.Init(game);
	menuTel.Init(game);

	dialogHandler.Init(game);

	int textsize = 19;
	dialogHandler.AddDialog(game, "Vicky: Wow grandpa! I can't even remember the last time we met.", 0, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Gramps: I'm jealous of all the people that haven't met you.", 0, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Gramps: Now shut it and help me distract... eh... entertain the neighbours while I break in... I mean run some errands.", 0, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Vicky: Okeydokes!", 0, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	
	dialogHandler.AddDialog(game, "Rocco: Whew, quite a place you got here grandpa! And all these years that I thought you hated me.!", 1, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Gramps: I don't exactly hate you, but if you were on fire and I had water, I'd drink it.", 1, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Gramps: Now pay attention.Go over to the neighbours and make sure they're occupied... And I'll prepare a... surprise... for them.A Christmas surprise.", 1, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Rocco: You have a heart of gold!", 1, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);

	dialogHandler.AddDialog(game, "Hayden: Gees gramps! When you wanted me to come over, I got so exited I spoiled myself with a beauty treatment.", 2, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Gramps: It looks like your face caught on fire and someone tried to put it out with a hammer.", 2, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Gramps: Now mosey your spoiled ass over to the neighbours and distract... eh socialize a bit while I get down to business... Yeah I got heaps to take care of.", 2, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Hayden: I'll do my best!", 2, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);

	dialogHandler.AddDialog(game, "Otter: Who are you and what am I doing here? You said something about a will and-", 3, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Gramps: Zip it. I want you to go over to my neighbours and give them a surprise performance.", 3, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Otter: Can I call you grandpa?", 3, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Gramps: Do you want me to throw up? Just do as I instructed, and you'll be my... favourite... grand... Just do as I said.", 3, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);

	dialogHandler.AddDialog(game, "*Sigh* Christmas is around the corner. I just know that my degenerate neighbours will ruin the holiday spirit with their loud blabbering and drama", 4, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "This year, I'm gonna do something about it.", 4, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	dialogHandler.AddDialog(game, "Better get on the phone and round up my useless relatives.", 4, -1, { 0, 0, 0 }, 90, game->screenHeigth - 220, textsize);
	
	//dialogHandler.playDialog(3);
	player.Initialize(game, "Data/animation.json");
	player.position.x = 2000;
	player.position.y = 1170;
	worldmap.LoadMap(game, "Data/Tiles/playerHouse.json");
	inputHandler.Init();
	game->camera.reset();
	game->camera.setFocus(player.position.x, player.position.y);
	graphicHelper.AddTextString("Some time later...", game->renderer, { 255, 255, 255 }, 450, game->screenHeigth/2-75, 50);
	usableChar.Initialize(game, "Data/animation_aerobic.json");
	usableChar.position.x = -1300;
	usableChar.position.y = -1200;

	lightning.Init(game);
	this->waitbox = false;
	changeToMinimap = false;
	
}

void PlayerHouseState::Cleanup()
{
	graphicHelper.Cleanup();
	menuTel.CleanUp();
	dialogHandler.Cleanup();
}

void PlayerHouseState::Pause()
{
}

void PlayerHouseState::Resume()
{


}

void PlayerHouseState::HandleEvents(GameEngine* game)
{
	inputHandler.CheckInput(game);
}

void PlayerHouseState::Update(GameEngine* game)
{
	
	if (game->isStart)
	{
		game->isStart = false;
		dialogHandler.playDialog(4);
	}
	dialogHandler.Update(game, &inputHandler);
	/*if 
	{


	}*/
	if (menuTv.isMenuOpen())
	{
		menuTv.Update(game, &player, &inputHandler);
	}
	else if (menuTel.isMenuOpen() || (menuTel.dialogHandler.play == true && menuTel.isMemberSelected))
	{
		menuTel.Update(game, &player, &inputHandler);
	}
	else if (menuTel.isMemberSelected)
	{
		player.position.x = 1200;
		player.position.y = 1200;
		game->camera.setFocus(player.position.x, player.position.y);
		menuTel.isMemberSelected = false;
		this->waitbox = true;
		this->waitboxTimer = 2000;

		if (game->usableChar_selected == 0)
		{
			usableChar.Initialize(game, "Data/animation_aerobic.json");
		}
		if (game->usableChar_selected == 1)
		{
			usableChar.Initialize(game, "Data/animation_sales.json");
		}
		if (game->usableChar_selected == 2)
		{
			usableChar.Initialize(game, "Data/animation_grandson.json");
		}
		if (game->usableChar_selected == 3)
		{
			usableChar.Initialize(game, "Data/animation_dressed_dude.json");
		}
		
		usableChar.position.x = 1300;
		usableChar.position.y = 1200;
		usableChar.sprite->SetCurrentBehaviour(4);
	}
	else
	{
		game->camera.update(game->millisecondFTime);
		Player tempPlayer = player;

		if (inputHandler.keyRunRight.pressed == true){
			tempPlayer.position.x += tempPlayer.movmentSpeed;
			tempPlayer.direction = 1;
			tempPlayer.sprite->SetCurrentBehaviour(2);
			game->camera.moveCameraToCenter(player.position.x + 40, player.position.y, 600);
		}

		else if (inputHandler.keyRunLeft.pressed == true){
			tempPlayer.position.x -= tempPlayer.movmentSpeed;
			tempPlayer.direction = -1;
			tempPlayer.sprite->SetCurrentBehaviour(2);
			game->camera.moveCameraToCenter(player.position.x - 40, player.position.y, 600);
		}
		else if (inputHandler.keyRunUp.pressed == true){
			tempPlayer.position.y -= tempPlayer.movmentSpeed;
			tempPlayer.direction = -1;
			tempPlayer.sprite->SetCurrentBehaviour(3);
			game->camera.moveCameraToCenter(player.position.x, player.position.y - 40, 600);
		}
		else if (inputHandler.keyRunDown.pressed == true){
			tempPlayer.position.y += tempPlayer.movmentSpeed;
			tempPlayer.direction = -1;
			tempPlayer.sprite->SetCurrentBehaviour(4);
			game->camera.moveCameraToCenter(player.position.x, player.position.y + 40, 600);
		}
		else if (inputHandler.KeyEscape.pressed == true){
			inputHandler.KeyEscape.pressed = false;
			//game->PushState(MenuState::Instance());
		}
		else
		{
			//game->camera.moveCameraTo(0,0,5000);
			tempPlayer.direction = 0;
			tempPlayer.sprite->SetCurrentBehaviour(1);
			game->camera.moveCameraToCenter(player.position.x, player.position.y, 1000);
		}

		if (!physics.CheckPlayerCollision(tempPlayer, worldmap))
		{
			player = tempPlayer;
		}

		SDL_Rect item = physics.checkIfPlayerCollideWithItem(tempPlayer, worldmap);
		if (inputHandler.keyReturn.pressed == true)
		{
			inputHandler.keyReturn.pressed = false;
			if (item.x != -1)
			{
				if (worldmap.getTileType(item.x, item.y, 2) == 2)
				{
					menuTv.SetOpen();
				}
				if (worldmap.getTileType(item.x, item.y, 2) == 3)
				{
					menuTel.SetOpen();
				}
			}
		}



		/*if (inputHandler.keyOpenMenu.pressed == true)
		{
			menuTv.SetOpen();
			inputHandler.keyOpenMenu.pressed = false;
		}*/
	}

	if (this->changeToMinimap && !dialogHandler.play)
	{
		this->changeToMinimap = false;
		game->ChangeState(WorldState::Instance());
	}
}

void PlayerHouseState::Draw(GameEngine* game)
{
	
	if (!this->waitbox)
	{
		//Draw the world
		worldmap.Draw(game);
	
		//do some fancy anitmation
		if (!menuTv.isMenuOpen() && !menuTel.isMenuOpen())
			player.sprite->PlayAnimation();
		player.Draw(game, game->millisecondFTime);
		usableChar.Draw(game, game->millisecondFTime);
		usableChar.sprite->PlayAnimation();
		//game->camera.setFocus(player.position.x, player.position.y);
		
		menuTv.Draw(game);
		menuTel.Draw(game);
		dialogHandler.Draw(game);
	}
	else
	{
		graphicHelper.PrintTextBuffer(game->renderer);
		waitboxTimer -= game->millisecondFTime;
		if (waitboxTimer <= 0)
		{
			this->waitbox = false;
			this->changeToMinimap = true;
			dialogHandler.playDialog(menuTel.selectedItem);
		}
	}
	
    //lightning.Draw(game, this->worldmap, this->player);
	
	/*
	if (game->camera.checkIfMoveCompleted())
	{
		int dx = rand() % 1000;
		int dy = rand() % 1000;

		if (dy > dx)
			game->camera.moveCameraTo(dx * -1, dy * -1, 5*dy);
		else
			game->camera.moveCameraTo(dx * -1, dy * -1, 5 * dx);
	}*/

}

