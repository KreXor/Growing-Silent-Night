#include "Player.h"
#include "Animation/AnimationReader.h"

void Player::Initialize(GameEngine* game, string spritePath)
{

	this->movmentSpeed = 4;
	this->position.x = 400;
	this->position.y = 1100;
	AnimationReader ar(spritePath);

	this->sprite = ar.LoadAnimations(spritePath, game);

	this->sprite->SetCurrentBehaviour(1);

}
