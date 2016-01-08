#include "BaseState.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Graph.h"
#include <SDL.h>

#include <iostream>

BaseState::BaseState(Uint8 r, Uint8 g, Uint8 b) : r_{r}, g_{g}, b_{b}
{
}

void BaseState::setColor(SDL_Texture* texture)
{
	SDL_SetTextureColorMod(texture, r_, g_, b_);
}

bool CowState::getAttacked(Graph* graph)
{
	// TODO: koe resetten
	std::cout << "HAAS VALT KOE AAN \n";
	cow_->reset(graph);
	return true;
}

bool RabbitState::getAttacked(Graph* graph)
{
	// TODO: rabbit resetten

	if (rabbit_->hasPill()) {
		std::cout << "HAAS GEEFT KOE PIL \n";
		return false;
	}
	else {
		std::cout << "KOE VALT HAAS AAN \n";
		rabbit_->reset(graph);
		return true;
	}

	return true;
}

/*TODO:
als haas gepakt is door de koe, dan
chanceToFleeState_ of
chanceToFindPillState_ of
chanceToFindWeaponState_ aanpassen (5 of zoiets eraf?)*/
