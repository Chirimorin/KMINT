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
	cow_->resetState();
	return true;
}

bool RabbitState::getAttacked()
{
	// TODO:
	// haas heeft pil
	// return false

	//zo nee
	// TODO: rabbit resetten

	/*if () {
		return false;
	}
	else {
		rabbit_->resetState();
		return true;
	}*/

	return true;
}

/*TODO:
als haas gepakt is door de koe, dan
chanceToFleeState_ of
chanceToFindPillState_ of
chanceToFindWeaponState_ aanpassen (5 of zoiets eraf?)*/
