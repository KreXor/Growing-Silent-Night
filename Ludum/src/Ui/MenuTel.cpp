#include "MenuTel.h"

void MenuTel::Init(GameEngine* game)
{

	bgImage = graphicHelper.Load_image("Data/Images/tel.bmp", game);

	graphicHelper.AddTextString("Who do you want to call?", game->renderer, { 0, 0, 0 }, 150, 140, 20);
	graphicHelper.AddTextString("Vicky - She's dumb as I am old, but she's got some acrobatic skills. Hopefully I won't live to see her kids.", game->renderer, { 0, 0, 0 }, 150, 170, 20);
	graphicHelper.AddTextString("Rocco - He's a smooth salesman, but that's about the only good thing I can think of. Brown-nosing slimeball.", game->renderer, { 0, 0, 0 }, 150, 200, 20);
	graphicHelper.AddTextString("Hayden - Thinks that watching every Idol-show from the last decade qualifies him as a singer. At least he's better than a coyote.", game->renderer, { 0, 0, 0 }, 150, 230, 20);
	graphicHelper.AddTextString("Otter - Heck, are we even related? Nevermind, I'll take what I can find.", game->renderer, { 0, 0, 0 }, 150, 260, 20);
	graphicHelper.AddTextString("Close Book", game->renderer, { 0, 0, 0 }, 150, 290, 20);


	int textSize = 21;
	int texttime = -1;
	dialogHandler.Init(game);
	dialogHandler.AddDialog(game, "Vicky: Hello?", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: Who the hell answers without stating their full name and wondering how they can be of service ?", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Vicky: G-grandpa? Is that you?", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: No it's Santa Claus, I've run out of cretins to pull the sled. OF COURSE IT'S GRANDPA. Now get over here, I need your assistance.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Vicky: B-but I've got a rost in the oven and-", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: Oh and I'll make sure you're getting what's coming to you in my last will and testament.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Vicky: I'll be there in a jiffy!", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: Moron.", 0, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);

	dialogHandler.AddDialog(game, "Rocco: Whaddayawant?", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: I'll open a can of smackeronis if you don't shape up your manners.", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Rocco: Huh? Look here, from my point of view that would be-", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: I'd like to see things from your point of view but I can't seem to get my head that far up my ass.", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Rocco: ...", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: I'm your grandfather and I'll reward you handsomly if you help me out.", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Rocco: Well why didn't you say so! I'll be there with the next flight!", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: Clown.", 1, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	
	dialogHandler.AddDialog(game, "Hayden: Are you calling from the talent show? Have I won??", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: Shut up and listen. You've won the opportunity to help your grandfather deal with som distressful matters.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Hayden: T-that's not the prize I was hoping for.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: That's the only thing you'll ever gonna get from life, now why aren't you here ten minutes ago?", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Hayden: B-but I have to prepare for an audition, I-", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: I'm not getting younger and you'll certainly benefit from this in my will.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Hayden: Favourite gramps! I'll run as fast as I can!", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: Useless.", 2, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	
	dialogHandler.AddDialog(game, "Otter: Yes?", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: No.", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Otter: What?", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: Stop whatever you're up to and get your lardy appearance here.", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Otter: Who is this? Do I know you?", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: No, but that's not important. What's important is that I've got a huge inheritance to distribute once I'm gone.", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Otter: But how do I benefit from-", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: You'll pass all my worthless relatives and get lousy rich.", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Otter: Mister, I don't know who you are or where you live, but I'm gonna find you even if it takes a lifetime!", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	dialogHandler.AddDialog(game, "Gramps: Or you can effing look it up in the phonebook, you arch idiot.", 3, texttime, { 0, 0, 0 }, 90, game->screenHeigth - 220, textSize);
	isMemberSelected = false;

}

bool MenuTel::isMenuOpen()
{
	return this->isOpen;

}

void MenuTel::SetOpen()
{
	this->isOpen = true;

}

void MenuTel::Update(GameEngine* game, Player* player, InputHandler* inputHandler)
{
	dialogHandler.Update(game, inputHandler);
	//player->position.x = 705;
	//player->position.y = 1170;
	player->sprite->SetCurrentBehaviour(3);
	game->camera.setZoomLevel(2);
	game->camera.setFocus(player->position.x, player->position.y);
	if (inputHandler->keyRunUp.pressed == true){
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = 4;
		inputHandler->keyRunUp.pressed = false;
	}
	else if (inputHandler->keyRunDown.pressed == true){
		selectedItem++;
		if (selectedItem > 4)
			selectedItem = 0;
		inputHandler->keyRunDown.pressed = false;
	}

	if (inputHandler->keyReturn.pressed == true)
	{
		inputHandler->keyReturn.pressed = false;

		if (selectedItem == 0 && game->usableChar_Vicky)
		{
			game->usableChar_selected = 0;
			game->usableChar_Vicky = false;
			this->isOpen = false;
			isMemberSelected = true;
			dialogHandler.playDialog(0);
		}
			
		if (selectedItem == 1 && game->usableChar_Rocco)
		{
			game->usableChar_Rocco = false;
			this->isOpen = false;
			isMemberSelected = true;
			game->usableChar_selected = 1;
			dialogHandler.playDialog(1);
		}
			
		if (selectedItem == 2 && game->usableChar_Hayden)
		{
			game->usableChar_Hayden = false;
			game->usableChar_selected = 2;
			this->isOpen = false;
			isMemberSelected = true;
			dialogHandler.playDialog(2);
		}
			//
		if (selectedItem == 3 && game->usableChar_Otter)
		{
			game->usableChar_selected = 3;
			game->usableChar_Otter = false;
			this->isOpen = false;
			isMemberSelected = true;
			dialogHandler.playDialog(3);
		}
			//dialogHandler.playDialog(2);
		if (selectedItem == 4)
		{
			//player->position.x = 705;
			//player->position.y = 1190;
			this->isOpen = false;
			dialogHandler.play = false;
			game->camera.setZoomLevel(1);
			game->camera.setFocus(player->position.x, player->position.y);
		}
		
	}

}

void MenuTel::Draw(GameEngine* game)
{
	if (this->isOpen || (isMemberSelected && dialogHandler.play == true))
	{	
		SDL_Rect r;
		r.x = 100;
		r.y = 100;
		r.w = game->screenWidth-100;
		r.h = 300;

		SDL_RenderCopy(game->renderer, this->bgImage, NULL, &r);

	
		r.x = 120;
		r.y = 170 + this->selectedItem*30;
		r.w = 20;
		r.h = 20;

		// Set render color to blue ( rect will be rendered in this color )
		SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);

		// Render rect
		SDL_RenderFillRect(game->renderer, &r);

		graphicHelper.PrintTextBuffer(game->renderer);

		dialogHandler.Draw(game);

		if (!game->usableChar_Vicky)
		{
			r.x = 150;
			r.y = 176;
			r.w = 800;
			r.h = 4;

			// Set render color to blue ( rect will be rendered in this color )
			SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(game->renderer, &r);
		}
		if (!game->usableChar_Rocco)
		{
			r.x = 150;
			r.y = 206;
			r.w = 850;
			r.h = 4;

			// Set render color to blue ( rect will be rendered in this color )
			SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(game->renderer, &r);
		}
		if (!game->usableChar_Hayden)
		{
			r.x = 150;
			r.y = 236;
			r.w = 1000;
			r.h = 4;

			// Set render color to blue ( rect will be rendered in this color )
			SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(game->renderer, &r);
		}
		if (!game->usableChar_Otter)
		{
			r.x = 150;
			r.y = 266;
			r.w = 700;
			r.h = 4;

			// Set render color to blue ( rect will be rendered in this color )
			SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(game->renderer, &r);
		}
	}

}

void MenuTel::CleanUp()
{

	this->dialogHandler.Cleanup();

}