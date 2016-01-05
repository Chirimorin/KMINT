#include "BaseState.h"
#include <SDL.h>

BaseState::BaseState(Uint8 r, Uint8 g, Uint8 b) : r_{r}, g_{g}, b_{b}
{
}

void BaseState::setColor(SDL_Texture* texture)
{
	SDL_SetTextureColorMod(texture, r_, g_, b_);
}

bool CowState::getAttacked()
{
	// TODO: koe resetten
	return true;
}

bool RabbitState::getAttacked()
{
	// TODO: rabbit resetten
	return true;
}

/*TODO:
als haas gepakt is door de koe, dan
chanceToFleeState_ of
chanceToFindPillState_ of
chanceToFindWeaponState_ aanpassen (5 of zoiets eraf?)*/
